#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <curses.h>
#else
#include <ncurses.h>
#endif

#include <curl/curl.h>

#define MAX_INPUT 1024

void send_webhook(const char *url, const char *message, const char *username) {
    CURL *curl = curl_easy_init();
    if (!curl) {
        mvprintw(14, 2, "Failed to initialize CURL.");
        refresh();
        return;
    }

    char json[2048];
    snprintf(json, sizeof(json),
             "{\"username\": \"%s\", \"content\": \"%s\"}",
             username, message);

    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
        mvprintw(14, 2, "CURL error: %s", curl_easy_strerror(res));
    else
        mvprintw(14, 2, "Message sent successfully!");

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    refresh();
}

int main() {
    char name[MAX_INPUT] = {0};
    char webhook_url[MAX_INPUT] = {0};
    char message[MAX_INPUT] = {0};

    initscr();
    noecho();
    cbreak();

    mvprintw(1, 2, "Inviare - Cross-Platform Webhook Sender");
    mvprintw(3, 2, "Name:");
    mvprintw(5, 2, "Webhook URL:");
    mvprintw(7, 2, "Message:");
    mvprintw(11, 2, "Press ENTER to send. Press any key to quit after sending.");

    move(3, 8);
    echo();
    getnstr(name, MAX_INPUT - 1);
    noecho();

    move(5, 16);
    echo();
    getnstr(webhook_url, MAX_INPUT - 1);
    noecho();

    move(7, 11);
    echo();
    getnstr(message, MAX_INPUT - 1);
    noecho();

    send_webhook(webhook_url, message, name);

    getch();
    endwin();
    return 0;
}
