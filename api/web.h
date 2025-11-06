#ifndef WEB_H
#define WEB_H

#include <string>

enum class HttpMethod
{
  GET,
  POST,
  PUT,
  DELETE,
  PATCH
};

struct Route
{
  // HttpMethod method;
  const char *path;
  void (*handler)(const char *body, std::string &outBody,
                  int &outStatus, std::string &outContentType);
};

// void handler_index(const char *body, std::string &outBody,
//                    int &outStatus, std::string &outContentType);
// void handler_assets(const char *body, std::string &outBody,
//                     int &outStatus, std::string &outContentType);
// void handler_files(const char *body, std::string &outBody,
//                    int &outStatus, std::string &outContentType);
// void handler_status(const char *body, std::string &outBody,
//                     int &outStatus, std::string &outContentType);
// void handler_settings(const char *body, std::string &outBody,
//                       int &outStatus, std::string &outContentType);

// Route routes[] = {
//     {"/", handler_index},             // will reroute to "/assets/index.html"
//     {"/assets/", handler_assets},     // provides all static files in folder "/assets/"
//     {"/files/", handler_files},       // handles all file on sd card
//     {"/status/", handler_status},     // get current status, e.g. isPaired, id,
//     {"/settings/", handler_settings}, // handles all settings, e.g. current pic, brightness, ...
// };

// start the web server
void webserver_start(int port);
// Handle incoming web requests (to be called in the main loop)
void webserver_handle_requests(void);
// Stop the web server
void webserver_stop(void);

#endif // WEB_H