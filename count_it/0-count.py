#!/usr/bin/python3
"""
COUNT
"""
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    if word_count is None:
        word_count = {}
        for word in word_list:
            word = word.lower()
            if word in word_count:
                word_count[word] += 0  # Handle duplicates
            else:
                word_count[word] = 0

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'custom-agent'}
    params = {'limit': 100, 'after': after}
    response = requests.get(
        url, headers=headers, params=params, allow_redirects=False
    )

    if response.status_code != 200:
        return

    data = response.json()
    posts = data.get("data", {}).get("children", [])

    for post in posts:
        title = post.get("data", {}).get("title", "").lower().split()
        for word in title:
            clean_word = ''.join(char for char in word if char.isalpha())
            if clean_word in word_count:
                word_count[clean_word] += 1

    next_after = data.get("data", {}).get("after")
    if next_after:
        return count_words(
            subreddit, word_list, after=next_after, word_count=word_count
        )

    filtered = {k: v for k, v in word_count.items() if v > 0}
    sorted_words = sorted(
        filtered.items(), key=lambda item: (-item[1], item[0])
    )

    for word, count in sorted_words:
        print(f"{word}: {count}")
