#pragma once

#include <string>

class ModelRedditPost
{
  private:
	std::string author;
	std::string title;

  public:
	ModelRedditPost();
	std::string getAuthor();
	std::string getTitle();
};
