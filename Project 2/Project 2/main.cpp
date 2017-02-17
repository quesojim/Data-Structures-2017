//
//  main.cpp
//  Project 2
//
//  Created by Colby Conkling on 2/16/17.
//  Copyright © 2017 Colby Conkling. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>
using namespace std;

class linkedlist{
    
public:
    int list [25][2];
    int top = -1;
    
    linkedlist(){
        
        //Initialize Array
        for (int i = 0; i < 25; i++){
            for (int j = 0; j < 2; j++){
                list[i][j]= NULL;
            }
        }
    }

    
    bool Empty(){
        
        bool b = true;
        for (int i = 0; i < 25; i++){
            for (int j = 0; j < 2; j++){
                if(list[i][j] != 0){
                    b = false;
                }
            }
        }
        
        return b;
    }
    
    
    int numElements(){
        if(top == -1){
            return 0;
        }
        
        int i = top;
        int count = 1;
        while(list[i][1] != -1){
            count++;
            i = list[i][1];
        }
        
        return count;
        
    }
    
    
    bool isFull(){
        
        if(numElements() == 25){
            return true;
        }
        else{
            return false;
        }
    }
    
    
    int Top(){
        
        int i = list[top][0];
        cout << "Stack Top Value: " << i << "\n\n\n" << endl;
        return i;
    }
    
    
    void push(int data){
        if (isFull() == false){
            
        srand (int(time(NULL))); //Seed for random number using time
        int randnum = rand() % 25;
        if (top == -1){
            
            top = randnum;
            list[randnum][0] = data;
            list[randnum][1] = -1;
            
        }
        else{
            while(list[randnum][0] != 0){
                randnum = rand() % 25;
            }
            
            list[randnum][0] = data;
            list[randnum][1] = top;
            top = randnum;
            
        }
        }
        else{
            cout << "ERROR!  Could not complete push operation.  List is full!" << endl;
        }
        
    }
    
    void pop(){
        
        if(Empty() != true){
            
        int temp = list[top][1];
        list[top][0] = NULL;
        list[top][1] = NULL;
        top = temp;
        
        }
        else{
            
            cout << "ERROR! Pop operation unsuccessful.  List is Empty!" << endl;
        }
        
    }
    
    void display(){
        
        int i = top;
        
        while(list[i][1] != -1){
            
            cout << "Data: " << setw(2) << list[i][0] << "   ";
            cout << "Index: " << setw(2) << i << "   ";
            cout << "Next: " << setw(2) << list[i][1] << endl << endl;
            i = list[i][1];
        }
        
        cout << "Data: " << setw(2) << list[i][0] << "   ";
        cout << "Index: " << setw(2) << i << "   ";
        cout << "Next: " << "NONE \n \n \n" << endl;
    }
};

int main() {
    
    linkedlist a;
    
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);
    a.push(9);
    a.push(10);
    a.display();
    
    a.push(20);
    a.display();
    a.push(30);
    a.display();
    a.push(40);
    a.display();
    
    a.Top();
    a.pop();
    a.display();
    
    a.Top();
    a.pop();
    a.display();
    
    a.Top();
    a.pop();
    a.display();
    
    return 0;
}
