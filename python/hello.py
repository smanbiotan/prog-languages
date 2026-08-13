'''
 --list--
list = ["apple", "banana", "mango", "dragonfruit", "watermelon"]
list.append("ninja")
list.extend(luckyNum)
print(list)
'''

'''
--tuples--
 coordinates = [(1, 2), (3, 4), (5, 6), (7, 8)]
 print(coordinates[3])
'''
 
'''
 --function-- 
def myfirstFunction(num1, num2):
  return num1 * num2
print(myfirstFunction(3, 5))
'''


'''
 --first practice problem--

num1 = float(input("Enter first number: "))
op = input("Enter operator: ")
num2 = float(input("Enter second number: "))

if op == "+":
  print(num1 + num2)
elif op == "-":
  print(num1 - num2)
elif op == "*":
  print(num1 * num2)
elif op == "/":
  print(num1 / num2)
else:
  print("Invalid Operator...")
'''

'''
 -- Dictionaries --

monthConversions = {
  "Jan": "January",
  "Feb": "Febuary",
  "Mar": "March",
  "Apr": "April",
  "May": "May",
  "Jun": "June",
  "Jul": "July",
  "Aug": "August",
  "Sep": "September",
  "Oct": "October",
  "Nov": "November",
  "Dec": "December"
}
print(monthConversions.get("Puke", "Not a valid key")) 
'''

'''
 -- while loop --

 i = 1

 while i <= 10:
  print(i)
  i += 1
'''
  
'''
 secret_word = "gwapo"
 guess = ""
 guess_count = 0
 guess_limit = 5
 out_of_guesses = False

 while guess != secret_word and not(out_of_guesses):
  if guess_count < guess_limit:
   guess = input("Enter guess: ")
    guess_count += 1;
  else:
    out_of_guesses = True
    
 if out_of_guesses:
  print("Out of guesses, YOU LOSE! ")
 else: 
 print("YOU WIN! ")
'''

'''
my_password = "gwapoko321"
guess_my_password = ""
guess_count = 0
guess_limit = 10
out_of_guesses = False

while guess_my_password != my_password and not(out_of_guesses):
  if guess_count < guess_limit:
    guess_my_password = input("Enter password: ")
    guess_count += 1
  else:
    out_of_guesses = True

if out_of_guesses:
  print("Your phone was locked in 1 hour, Try again later...")
else: 
  print("Congrats! You unlocked your phone...")
'''

'''
-- for loop --
names = ["Sherwin", "Sher Daks", "Sher Gwapo"]

<<------------->>
for len in range(len(names)):
  print(names[len])
  
fruits = ["apple", "banana", "mango", "dragonfruit", "watermelon"]
for fruit in fruits:
  print(fruit)
  if fruit == "dragonfruit":
    break
    
def raise_to_power(base_num, pow_num):
    result = 1
    for index in range(pow_num):
        result *=  base_num
    return result

print(raise_to_power(2, 4))
'''

'''
--- 2D GRID---
twoD_grid = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9],
  [0]
]

for row in twoD_grid:
  print(row)
  for col in row:
    print(col)
'''

'''
--- building translator---

def translate(phrase):
  translation = ""
  for letter in phrase:
    if letter in "AEIOUaeiou":
      translation = translation + "g"
    else:
      translation = translation + letter
      return translation
      
print(translate(input("Enter a phrase: ")))
'''

'''
try:
  test = 10/0
  number = int(input("Enter a number: "))
  print(number)
except ZeroDivisionError as err:
  print(err)
except ValueError:
  print("Invalid Input...")
'''

'''
--- FILE HANDLING ---

<- PY READING FILES ->
Student_txt = open("Student.txt", "r")
print(Student_txt.read())

Student_txt.close()

Student_txt = open("Student.txt", "w")
Student_txt.write("Matthew - 2nd year BSIT")

Student_txt.close()

<- USING THE "WITH" STATEMENT ->
with open("Student.txt", "a") as Student_txt:
  Student_txt.write("\nMatthew - 2nd year BSIT")

with open("Student.txt", "r") as Student_txt:
  print(Student_txt.read())

Student_txt.close()

<- PY DELETE FILES ->
import os
if os.path.exists("test.txt"):
  os.remove("test.txt")
else:
  print("File does not exists!")
'''

name = input("Enter your name: ")

address = input("Enter your address: ")

birthday = input("Enter your birthday (MM/DD/YYYY): ")

email = input("Enter your email: ");

phone_number = input("Enter your phone number: ")

motto = input("Enter your motto: ")
print("")

print(f"Name: " + name)
print(f"Address: " + address)
print(f"Birthday: " + birthday)
print(f"Phone Number: " + phone_number)
print(f"Motto " + motto)

