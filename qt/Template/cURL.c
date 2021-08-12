#include <curl/curl.h>
#include <string>

using namespace std;

//cURL GET needed function
size_t writeFunction(void *ptr, size_t size, size_t nmemb, std::string* data) {
    data->append((char*) ptr, size * nmemb);
    return size * nmemb;
}

int main(){

    char *URL_STR = "https://iot-try.herokuapp.com/sensors";

    //cURL code GET
    /*auto curl = curl_easy_init();
    if (curl) {
        string response_string;

        curl_easy_setopt(curl, CURLOPT_URL, URL_STR);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunction);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response_string);//no header check cause im lazy

        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl = NULL;

        QString qstr = QString::fromStdString(response_string.substr(0,6));
        ui->label->setText(qstr);
    }*/


    //cURL code POST
    auto curl = curl_easy_init();
    if (curl) {
        char *data = "moist=13&light=11&temp=3";

        curl_easy_setopt(curl, CURLOPT_URL, URL_STR);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long) strlen(data));
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        curl_easy_perform(curl);

        QString qstr = QString::fromStdString(data);
        ui->label->setText(qstr);
    }
    return 0;
}