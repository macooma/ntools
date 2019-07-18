/*************************************************************************

 statistics.h
 Copyright (C) 2010, Norbert Vegh
 Norbert Vegh, ntools@norvegh.com

 This program is free software; you can redistribute it and/or modify it
 under the terms of the GNU General Public License as published by the
 Free Software Foundation; either version 2 of the License, or (at your
 option) any later version.

*************************************************************************/
 
#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <string>

#include "linkedlist.h"

using namespace std;

struct Results
{
	Results();
	void add( string *mystring );
	
	int sock;
	LinkedList <string> data;
};

class Statistics
{
 public:
	unsigned long packets;
	long long bytes;
	unsigned long losses;
	unsigned long misorderings;
	long long delay;
	long numofdelays;
	unsigned long minDelay;
	unsigned long maxDelay;
	int invalid;  // indicates that the delay values are invalid (clock sync problem)
	int foreign;  // indicates that foreign packets were received (not generated by ngen)
	
	Statistics();
	~Statistics();
	void clear();
	void addDelay( unsigned long delay );
	unsigned long getPercentile( float p );
	
 private:
	vector<unsigned long> arr;
	int sorted;
	void heapSort();
	void siftDown( int root, int bottom );
};


#endif
