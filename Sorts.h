
#include <vector>
#include <string>
#include <tuple>
#pragma once
//this is NOT the sort function
void mergepair(std::vector<std::pair<int,int>>& list,int start,int middle,int end){
    //size of first half
    //we add one since we are including the middle index
    int s1 = middle-start+1;
    //size of second half
    //we don't need anything else since we are not including the middle index
    int s2 = end-middle;

    //vector for first half
    std::vector<std::pair<int,int>> fhalf;
    for(int i = 0;i<s1;i++){
        //push back the values of the first half of the sub vector
        fhalf.push_back(list[start+i]);
    }

    //vector for second half
    std::vector<std::pair<int,int>> shalf;
    for(int i = 0;i<s2;i++){
        //push back the values of the second half
        //add 1 to the index since we do not want to include the middle index
        shalf.push_back(list[middle+1+i]);
    }
    int i = 0;//index of ith element of first half
    int j = 0;//index of the jth element of the second half;
    int k = start; //index of the start of the sub vector relative to the original vector

    while(i!=s1&&j!=s2){
        //if ith frequency of first half is greater than jth frequency of second half put jth vector into kth position
        if(fhalf[i].first>shalf[j].first){
            list[k]=shalf[j];
            j++;
            k++;
        }
        else{
            list[k]=fhalf[i];
            k++;
            i++;
        }
    }
    //if firsthalf isnt "empty" then put remaining elements into the original vector
    while(i!=s1){
        list[k]=fhalf[i];
        k++;
        i++;
    }
    while(j!=s2){
        list[k]=shalf[j];
        k++;
        j++;
    }

}

//This IS the sort function for vector pairs where the first element is the frequency and the last element is whether or not it is a chain
//start is the first index
//end is the last VALID index
void mergeSortPair(std::vector<std::pair<int,int>>& list,int start,int end){
    if(start<end){
        int middle = (start+end)/2;
        mergeSortPair(list,start,middle);
        mergeSortPair(list,middle+1,end);
        mergepair(list,start,middle,end);
    }
}


int partitionpair(std::vector<std::pair<int,int>>& list,int start,int end){
    //let the pivot be the first element of the sub vector
    std::pair<int,int> pivot = list[start];
    //up starts at start and down starts at the end of the sub vector
    int up = start;
    int down = end;

    while(up<down){
        for(int i = up;up<end;i++){
            //if up frequency is greater than the frequency of the pivot stop
            if(list[up].first>pivot.first){
                break;
            }
            //otherwise keep going forward in the vector
            up++;
        }
        //if down frequency is less than the frequency of the pivot stop
        for(int i = down;i>start;i--){
            if(list[down].first<pivot.first){
                break;
            }
            //otherwise keep going backwards in the vector
            down--;
        }
        if(up<down){
            //as long as the index up is before the index down swap the pairs at the index up and down
            std::pair<int,int> temp = list[up];
            list[up]=list[down];
            list[down]=temp;
        }
    }
    //once up and down cross each other or up is infront of down
    //swap the pivot and down pair since we want the left side of the pivot to be frequencies less than it
    list[start] = list[down];
    list[down]=pivot;
    return down;

}
//sorts by the first value of the pair
void quickSortPair(std::vector<std::pair<int,int>>& list,int start,int end){
    if(start<end){
        //parition the vector where the first element is placed in its correct position
        int pivot = partitionpair(list,start,end);
        //the index at the pivot is "sorted" so we want to look at the 2 sub arrays which are divided by the pivot but neither include it
        quickSortPair(list,start,pivot-1);
        quickSortPair(list,pivot+1,end);

    }
}



//replace any references to "pair" with tuple for comments
int partition3tuple(std::vector<std::tuple<std::string,int,int>>& list,int start,int end){
    //let the pivot be the first element of the sub vector
    std::tuple<std::string,int,int> pivot = list[start];
    //up starts at start and down starts at the end of the sub vector
    int up = start;
    int down = end;

    while(up<down){
        for(int i = up;up<end;i++){
            //if up frequency is greater than the frequency of the pivot stop
            if(std::get<1>(list[up])>std::get<1>(pivot)){
                break;
            }
            //otherwise keep going forward in the vector
            up++;
        }
        //if down frequency is less than the frequency of the pivot stop
        for(int i = down;i>start;i--){
            if(std::get<1>(list[down])<std::get<1>(pivot)){
                break;
            }
            //otherwise keep going backwards in the vector
            down--;
        }
        if(up<down){
            //as long as the index up is before the index down swap the pairs at the index up and down
            std::tuple<std::string,int,int> temp = list[up];
            list[up]=list[down];
            list[down]=temp;
        }
    }
    //once up and down cross each other or up is infront of down
    //swap the pivot and down pair since we want the left side of the pivot to be frequencies less than it
    list[start] = list[down];
    list[down]=pivot;
    return down;

}
//sorts by the second value of the 3-tuple
void quickSort3tuple(std::vector<std::tuple<std::string,int,int>>& list,int start,int end){
    if(start<end){
        //parition the vector where the first element is placed in its correct position
        int pivot = partition3tuple(list,start,end);
        //the index at the pivot is "sorted" so we want to look at the 2 sub arrays which are divided by the pivot but neither include it
        quickSort3tuple(list,start,pivot-1);
        quickSort3tuple(list,pivot+1,end);

    }
}


void merge3tuple(std::vector<std::tuple<std::string,int,int>>& list,int start,int middle,int end){
    //size of first half
    //we add one since we are including the middle index
    int s1 = middle-start+1;
    //size of second half
    //we don't need anything else since we are not including the middle index
    int s2 = end-middle;

    //vector for first half
    std::vector<std::tuple<std::string,int,int>> fhalf;
    for(int i = 0;i<s1;i++){
        //push back the values of the first half of the sub vector
        fhalf.push_back(list[start+i]);
    }

    //vector for second half
    std::vector<std::tuple<std::string,int,int>> shalf;
    for(int i = 0;i<s2;i++){
        //push back the values of the second half
        //add 1 to the index since we do not want to include the middle index
        shalf.push_back(list[middle+1+i]);
    }
    int i = 0;//index of ith element of first half
    int j = 0;//index of the jth element of the second half;
    int k = start; //index of the start of the sub vector relative to the original vector

    while(i!=s1&&j!=s2){
        //if ith frequency of first half is greater than jth frequency of second half put jth vector into kth position
        if(std::get<1>(fhalf[i])>std::get<1>(shalf[j])){
            list[k]=shalf[j];
            j++;
            k++;
        }
        else{
            list[k]=fhalf[i];
            k++;
            i++;
        }
    }
    //if firsthalf isnt "empty" then put remaining elements into the original vector
    while(i!=s1){
        list[k]=fhalf[i];
        k++;
        i++;
    }
    while(j!=s2){
        list[k]=shalf[j];
        k++;
        j++;
    }

}

//This IS the sort function for vector 3-tuples where the second element is the frequency and the last element is whether or not it is a chain
//start is the first index
//end is the last VALID index
void mergeSort3tuple(std::vector<std::tuple<std::string,int,int>>& list,int start,int end){
    if(start<end){
        int middle = (start+end)/2;
        mergeSort3tuple(list,start,middle);
        mergeSort3tuple(list,middle+1,end);
        merge3tuple(list,start,middle,end);
    }
}







