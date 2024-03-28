#include <stdio.h>
#include<stdlib.h>
#include <curl/curl.h>
#include "libxml/HTMLparser.h"
#include "libxml/xpath.h"
#include <string.h>


#define MAX_PRODUCTS 16

typedef struct{
    char *url;
    char *image;
    char *name;
    char *price;
} PokemonProduct;


struct CURLResponse{
    char *html;
    size_t size;
};

static size_t WriteHTMLCallback(void *contents, size_t size, size_t nmemb, void *userp){
    size_t realsize = size * nmemb;
    struct CURLResponse *mem = (struct CURLResponse *)userp;
    char *ptr = realloc(mem->html, mem->size + realsize + 1);

    if (!ptr){
        printf("not enough memory available(realloc returned Null)\n");
        return 0;
    }
    
    mem->html = ptr;
    memcpy(&(mem->html[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->html[mem->size] = 0;

    return realsize;
}



struct CURLResponse GetRequest(CURL *curl_handle, const char *url){
    CURLcode res;
    struct CURLResponse response;

    // initiates the response
    response.html = malloc(1);
    response.size = 0;

    // specifies URL to GET
    curl_easy_setopt(curl_handle, CURLOPT_URL, url);

    curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, WriteHTMLCallback);
    curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, (void *)&response);

    //sendsALL DATA RETURNED BY SERVER
    curl_easy_setopt(curl_handle, CURLOPT_USERAGENT, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/117.0.0.0 Safari/537.36");

    //performs get request
    res = curl_easy_perform(curl_handle);

    // checks for HTTP errors
    if (res != CURLE_OK){
        fprintf(stderr, "GET request failed %s\n", curl_easy_strerror(res));
    }
    return response;
}



int main(void){
    // initiates curl globally
    curl_global_init(CURL_GLOBAL_ALL);

    // initiates a curl  instance
    CURL *curl_handle = curl_easy_init();

    PokemonProduct products[MAX_PRODUCTS];
    int productCount = 0;

    //retrieves html of target page
    struct CURLResponse response = GetRequest(curl_handle, "https://scrapeme.live/shop/");


    htmlDocPtr doc = htmlReadMemory(response.html, (unsigned long)response.size, NULL, NULL, HTML_PARSE_NOERROR);
    xmlXPathContextPtr context = xmlXPathNewContext(doc);
    xmlXPathObjectPtr productHTMLElements = xmlXPathEvalExpression((xmlChar *)"//li[contains(@class, 'product')]", context);

    // prints the html content
    printf("%s\n", response.html);

    // scraping logic
    for (int i = 0; i < productHTMLElements->nodesetval->nodeNr; ++i){
        //gets the current element of the loop
        xmlNodePtr productHTMLElement = productHTMLElements->nodesetval->nodeTab[i];

        xmlXPathSetContextNode(productHTMLElement, context);
        xmlNodePtr urlHtMLElement = xmlXPathEvalExpression((xmlChar *)".//a", context)->nodesetval->nodeTab[0];
        char *url = (char *)xmlGetProp(urlHtMLElement, (xmlChar *)"href");
        xmlNodePtr imageHTMLElement = xmlXPathEvalExpression((xmlChar *)".//a/img", context)->nodesetval->nodeTab[0];
        char *image = (char *) (xmlGetProp(imageHTMLElement, (xmlChar *)"src"));
        xmlNodePtr nameHTMLElement = xmlXPathEvalExpression((xmlChar *)".//a/h2", context)->nodesetval->nodeTab[0];
        char *name = (char *) (xmlNodeGetContent(nameHTMLElement));
        xmlNodePtr priceHTMLElement = xmlXPathEvalExpression((xmlChar *)".//a/span", context)->nodesetval->nodeTab[0];
        char *price = (char *) (xmlNodeGetContent(priceHTMLElement));

        // stores scrapped data in pokemonproduct
        PokemonProduct product;
        product.url = strdup(url);
        product.image = strdup(image);
        product.name = strdup(name);
        product.price = strdup(price);

        //frees up unused resources
        free(url);
        free(image);
        free(name);
        free(price);

        //adds new product to array
        products[productCount] = product;
        productCount++;
        }

        free(response.html);
        //frees up libxml2 resources
        xmlXPathFreeContext(context);
        xmlFreeDoc(doc);
        xmlCleanupParser();

        // clean up the curl instance
        curl_easy_cleanup(curl_handle);

        // cleans crl resources
        curl_global_cleanup();

    FILE *csvFile = fopen("products.cvs", "w+");
    if (csvFile == NULL){
        perror("Failed to open CSV output file!");
        return 1;
    }

    fprintf(csvFile, "url,image,name,price\n");

    for(int i = 0; i < productCount; i++){
        fprintf(csvFile, "%s,%s,%s,%s\n", products[i].url, products[i].image, products[i].name, products[i].price);
    }
    fclose(csvFile);

    for (int i=0; i < productCount; i++){
        free(products[i].url);
        free(products[i].image);
        free(products[i].name);
        free(products[i].price);
    }

    return 0;
}

