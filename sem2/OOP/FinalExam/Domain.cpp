//
// Created by Razvan on 7/5/2022.
//

#include "Domain.h"

#include <utility>

Post::Post(int id, std::string text, int date, int time, std::string user) : id(id), text(std::move(text)),
                                                                                           date(date), time(time),
                                                                                           user(std::move(user)) {}

int Post::getId() const {
    return id;
}

void Post::setId(int id) {
    Post::id = id;
}

const std::string &Post::getText() const {
    return text;
}

void Post::setText(const std::string &text) {
    Post::text = text;
}

int Post::getDate() const {
    return date;
}

void Post::setDate(int date) {
    Post::date = date;
}

int Post::getTime() const {
    return time;
}

void Post::setTime(int time) {
    Post::time = time;
}

const std::string &Post::getUser() const {
    return user;
}

void Post::setUser(const std::string &user) {
    Post::user = user;
}

std::ostream &operator<<(std::ostream &os, const Post &post) {
    os << post.id << "," << post.text << "," << post.date << "," << post.time << ","
       << post.user;
    return os;
}

Topic::Topic(const std::string& n) {
    this->name=std::move(n);
}
