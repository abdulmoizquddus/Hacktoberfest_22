'''
Python Implementation of the popular game Hangman
Author: D1Dayer99
'''

import random
import re

class Hangman:

    def __init__(self): #initialize all the variables and functions
        self.word = self.generate_word()
        self.lives = self.track_lives()
        self.blanks = self.display_blank()
        self.guessed_char = self.track_guessed_char()
        self.guesses = self.track_guesses()

    def generate_word(self): #randomly picks a word out of the txt file
        file = open("ten_thousand_words.txt","r")
        ran_word = random.choice(file.readlines())
        ran_word = ran_word.strip()
        return ran_word

    def track_lives(self): #tracks how many lives the playes has
        p_lives = 6
        print(f"You have {p_lives} lives.")
        return p_lives

    def display_blank(self): #checks the length of the word and prints out the underscores
        word_length = len(self.word)
        blanks="_"*word_length
        print(blanks)
        return blanks
    
    def track_guessed_char(self): #tracks all the character that was guesses before
        guessed_char =[]
        return guessed_char

    def find_chars(self):#find the index of all the characters thet have been guessed correctly
        matches = re.finditer(self.p_guess,self.word)
        matches_idx = [match.start() for match in matches]
        return matches_idx

    def correct_guess(self): #if the guess was correct
        print("Correct Guess")
        self.blanks = ""
        for char in self.word:
            if char in self.guessed_char:
                self.blanks += char
            else:
                self.blanks += "_"
        if "_" not in self.blanks:
            print("Congratulations, you guessed the word")
            self.lives = 0
        print(self.blanks)
        return self.blanks

    def wrong_guess(self): #if the guess was wrong
        print("The character is not inside the word")
        self.lives -=1
        if self.lives != 0:
            print(f"You still have {self.lives} lives")
            print(self.blanks)
        else:
            print(f"The correct word was {self.word}.")
            print("0 lives left. Disappointing.")
        
    
    def track_guesses(self): #asks for an input and checks the character
        while self.lives >0:
            self.p_guess = input("Guess a character: ")
            if self.p_guess in self.guessed_char:
                print("The character has already been guessed, please choose another one: ")
                print(self.blanks)
            elif self.p_guess in self.word:
                self.indices = self.find_chars()
                self.guessed_char.append(self.p_guess)
                self.correct_guess()
            else:
                self.guessed_char.append(self.p_guess)
                self.wrong_guess()

game1 = Hangman()
