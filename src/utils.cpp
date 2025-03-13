#include "../include/utils.hpp"

bool isEmail(const std::string &email){
    auto position = email.find('@');
    if(position == std::string::npos) return false;

    std::string domain = email.substr(position + 1);
    std::vector<std::string> allowed_domains = {
        "gmail.com",      "outlook.com",   "yahoo.com",     "hotmail.com",
        "icloud.com",     "aol.com",       "zoho.com",      "protonmail.com",
        "yandex.com",     "mail.com",      "gmx.com",       "live.com",
        "inbox.com",      "fastmail.com",  "icloud.com",    "rocketmail.com",
        "rediffmail.com", "cox.net",       "earthlink.net", "att.net",
        "verizon.net",    "sbcglobal.net", "ymail.com",     "me.com",
        "msn.com",        "bluewin.ch",    "t-online.de",   "web.de",
        "libero.it",      "alice.it",      "tin.it"
    };
    bool valid_domain = false;

    for(const std::string &allowed_domain : allowed_domains){
        if(domain == allowed_domain){
            valid_domain = true;
            break;
        }
    }

    return valid_domain;
}