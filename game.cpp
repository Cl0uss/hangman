#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <string>
#include <random>
using namespace std;
void game(string secret,string progress,int wrong, string alphabet,int guessed,string save)
{
cout<<"\033[2J\033[H";
if (guessed==5)
{
cout<<"You won!\n";
return;
}//if condition
switch (wrong)
{
case 0:
{
cout<<"       ______\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |\n";
cout<<"      |\n"; 
cout<<"      |\n"; 
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"  ____|____\n";
break;
}//case 0
case 1:
{
cout<<"       ______\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      O\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"  ____|____\n";
break;
}//case 1
case 2:
{
cout<<"       ______\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      O\n";
cout<<"      |      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"  ____|____\n";
break;
}//case 2
case 3:
{
cout<<"       ______\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      O\n";
cout<<"      |      |\\\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"  ____|____\n";
break;
}//case 3
case 4:
{
cout<<"       ______\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      O\n";
cout<<"      |     /|\\\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"  ____|____\n";
break;
}//case 4
case 5:
{
cout<<"       ______\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      O\n";
cout<<"      |     /|\\\n";
cout<<"      |      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"  ____|____\n";
break;
}//case 5
case 6:
{
cout<<"       ______\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      O\n";
cout<<"      |     /|\\\n";
cout<<"      |      |\n";
cout<<"      |     /\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"  ____|____\n";
break;
}//case 6
case 7:
{
cout<<"       ______\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      |\n";
cout<<"      |      X\n";
cout<<"      |     /|\\\n";
cout<<"      |      |\n";
cout<<"      |     / \\\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"      |\n";
cout<<"  ____|____\n";
cout<<"You lost. Answer was - "<<save<<endl;
return;
break;
}//case 7 (loose)
}//switch
cout<<"\n"<<alphabet<<endl<<progress<<endl;
cout<<"\nWrite a letter: ";
char letter;
cin>>letter;
cout<<endl;
for (int i=0;i<35;i++)
{
if (alphabet[i]==letter)
{
alphabet[i]='_';
}//if
}//for loop
bool check=0;
for (int i=0;i<5;i+=1)
{
if (secret[i]==letter)
{
secret[i]='&';
check=1;
progress[i*2]=letter;
guessed++;
}//if condition
}//for loop
if (check==1)
{
cout<<"You guessed a letter\n";
sleep(2);
game(secret,progress,wrong,alphabet,guessed,save);
}
else
{
cout<<"Wrong letter\n";
wrong++;
sleep(2);
return game(secret,progress,wrong,alphabet,guessed,save);
}//else
}//void
int main()
{
srand(time(NULL));
//
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> dis(0,170);
int random=dis(gen);
//random number generator
string words[] = {"apple", "happy", "smile", "table", "story", "chair", "cloud", "green", "funny", "music", "dance", "puppy", "beach", "magic",
"color", "bunny", "swing", "robot", "fairy", "jelly", "sunny", "snack", "lucky", "dream", "giant", "ocean", "silly", "zebra", "daisy", "laser",
 "flame", "honey","river", "sugar", "dream", "cheer", "laugh", "chase", "spark", "spark", "happy", "globe", "melon", "peace", "cloud", "smile",
 "sweet", "peace","chirp", "candy", "frost", "grape", "heart", "happy", "jolly", "kitty", "light", "magic", "novel", "oasis", "peace", "quack",
 "robot", "silly","tiger", "upend", "vivid", "wings", "yummy", "zooey", "apple", "bunny", "comic", "dance", "elbow", "fairy", "girly", "happy",
 "inbox", "juice","kitty", "lucky", "mango", "novel", "oasis", "puppy", "quack", "robin", "sunny", "tiger", "umbra", "vivid", "whale", "yummy",
 "zebra", "abide","blink", "candy", "daisy", "elbow", "frost", "giant", "happy", "inbox", "jolly", "kitty", "laser", "melon", "novel", "oasis",
 "peace", "quack","robot", "silly", "tiger", "umbra", "vivid", "wings", "yummy", "zebra", "agile", "bunny", "comic", "dance", "elbow", "fairy",
 "girly", "happy","inbox", "juice", "kitty", "lucky", "mango", "novel", "oasis", "puppy", "quack", "robin", "sunny", "tiger", "umbra", "vivid",
 "whale", "yummy", "zebra", "apple","bunny", "comic", "dance", "elbow", "fairy", "girly", "happy", "inbox", "juice", "kitty", "lucky", "mango",
 "novel", "oasis", "puppy", "quack","robin", "sunny", "tiger", "umbra", "vivid", "whale", "yummy", "zebra"};
string secret=words[random];
game(secret,"_ _ _ _ _",0,"abcdefghijklmnopqrstuvwxyz",0,secret);
}//main
