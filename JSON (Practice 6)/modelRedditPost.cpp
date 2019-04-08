#include "modelRedditPost.hpp"

ModelRedditPost::ModelRedditPost()
{
}

std::string ModelRedditPost::getAuthor() const
{
	return author;
}

std::string ModelRedditPost::getTitle() const
{
	return title;
}