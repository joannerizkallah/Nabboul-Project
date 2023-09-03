#!/usr/bin/env python
# coding: utf-8

# In[3]:



import time
import sklearn
import pyttsx3

import re

import speech_recognition as sr

from sklearn.metrics.pairwise import cosine_similarity
from sklearn.feature_extraction.text import TfidfVectorizer


def extract_distance(text):
    ans= re.search(r'[\d]+',text)
    if (ans!=None):
        return ans.group()
    else:
        return "50"

def response(question):
    new_sentences = ["Do trick one","trick one", "one", "do one","perform trick one", "execute trick one", "one one" , "one trick one", "big one", "on","onn","gone","1","2", "trick two", "do trick two", "two", "too", "to" ]

    tfivect=TfidfVectorizer()
    new_sentences.append(question)
    tfi= tfivect.fit_transform(new_sentences)
    cossim= cosine_similarity(tfi[-1],tfi)
    index=cossim.argsort()[0][-2]
    flat = cossim.flatten()
    flat.sort()
    if (flat[-2]==0):
        text_to_speech("I am sorry, I do not understand what you are asking me.")
        return ("I am sorry, I do not understand what you are asking me.")
    else:
        return new_sentences[index]
def action(question):
    ans= response(question)
    if((ans == "Do trick one") | (ans == "trick one") | (ans == "do one") | (ans == "one") | (ans == "perform trick one") | (ans == "execute trick one") |(ans == "one one") | (ans == '1') | (ans == "one trick one") | (ans == 'big one') | (ans == 'on') | (ans == "onn") | (ans == "gone")):
        text_to_speech("Alright, prepare for the card trick!")
        trick1()
    elif ((ans == "Do trick two") | (ans == "trick two") | (ans == "2") | (ans == "two") | (ans == "too") | (ans == "to")):
        text_to_speech("My favorite trick coming right up")
        trick2()
    #elif ((ans == "last") | (ans == "last trick") | (ans == "do last trick") | (ans == "do last") | "last click"):
       # text_to_speech("Joanne and Nadine are superb")
    else:
        text_to_speech("I am sorry, I do not understand what you are asking me.")



def speech():
    r = sr.Recognizer()

    with sr.AudioFile("hello.wav") as source:
        audio = r.record(source)
        # recognize (convert from speech to text)
        text = r.recognize_google(audio,language='en')
    return (text)


def speech_to_text():
    with sr.Microphone() as source:
        r = sr.Recognizer()
        r.adjust_for_ambient_noise(source)
        text_to_speech("Nabboul will start recording after this message:")
        # time.sleep(1)
        # print("3")
        # time.sleep(1)
        # print("2")
        # time.sleep(1)
        # print("1")
        # time.sleep(1)
        # print("Recording... Leave a message and wait for a few seconds")
        audio=r.listen(source)
        text_to_speech("Done recording.")

        try:
            text=r.recognize_google(audio,language='en')
            return text
        except sr.UnknownValueError:
            return("Please enter a valid input.")


def text_to_speech(response):
    engine = pyttsx3.init()
    voices = engine.getProperty('voices')
    engine.setProperty('voice', voices[0].id)
    engine.setProperty('rate', 140)
    engine.setProperty('volume', 0.9)
    engine.say(response)
    engine.runAndWait()
    
def trick1():
    time.sleep(4)
    text_to_speech("Hello welcome to Nabboul's magic show")
    text_to_speech("Please choose a card and memorize it")
    time.sleep(8)
    text_to_speech("Where's the card? Hahaha")
    
def trick2():
    time.sleep(3)
    text_to_speech("No, I am the magician and he is the assistant.")
    time.sleep(12)
    text_to_speech("Show me all the cards assistant")
    time.sleep(3)
    text_to_speech("Ok, I am now going to guess the color of the card") #33s
    time.sleep(25)
    text_to_speech("Mmmmmm")
    time.sleep(5)
    text_to_speech("Oh, I know what your color is! It's black")
    text_to_speech("I suspect the card you picked is starting from the top, the sevent, eighth, or nine.")
    text_to_speech("1.")
    text_to_speech("2.")
    text_to_speech("3.")
    text_to_speech("4.")
    text_to_speech("5.")
    text_to_speech("6.")
    time.sleep(3)
    text_to_speech("Let's see...")
    text_to_speech("hmmmmm")
    time.sleep(15)
    text_to_speech("I know what your card is. It's sixth of spades.")


question = speech_to_text()
print(question)
value = action(question)
print(value)

# In[ ]:




