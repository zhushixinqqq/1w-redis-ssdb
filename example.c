#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <hiredis.h>
#include <sys/time.h> 
#include <sys/types.h>  
#include <pthread.h>  
#include <assert.h> 
#define EQUIPMENT 150
#define SIMULATE 300
#define STATUS 200
#define AREA 6
#define REDIS_HOST        "127.0.0.1"
#define REDIS_PORT        6379
#define NUM_THREADS 4 
int Random(int m, int n)
{
	int pos, dis;
	if (m == n)
	{
		return m;
	}
	else if (m > n)
	{
		pos = n;
		dis = m - n + 1;
		return rand() % dis + pos;
	}
	else
	{
		pos = m;
		dis = n - m + 1;
		return rand() % dis + pos;
	}
}
void *  
myprocess2 ()  
{  
    //printf ("threadid is, working on task\n"); 
	int area_start=71;
	//area_start=*((int *)args);
	printf ("threadid is, working on task %d\n",area_start); 
	int i, j,k,m, n;
	char value[100] = {0};
	char key[50] = {0};
	char command[200] = {0};
	struct  timeval  start;
	struct  timeval  end;
	struct  timeval  start2;
	struct  timeval  end2;
	unsigned long timer;
	//TStrStrMap::iterator p;
	int szTime = (int)time(NULL);
	//srand(szTime);
	m = 200;
	n = 240;
	int num=0;
	//redisReply *replay=NULL;
	redisReply *replay=NULL;
	redisReply **replies;
	int timeout=10000;
	struct timeval tv;
	tv.tv_sec=timeout/1000;
	tv.tv_usec=timeout*1000;
	float ac;
	int ad;
	redisContext* c=redisConnect("127.0.0.1",6379);
	redisReply *reply;
	if(c->err)
	{
		printf("connect error!\n");
		//return;
	}
	//replies = malloc(sizeof(redisReply*) * num);
	
	timer=0;
	gettimeofday(&start,NULL);
	ad=1;
	szTime = (int)time(NULL);
	srand(szTime);
	//string command;
	ac=1;
	//printf("count is%d",ac);
	//ac = (Random(m, n) / 10.0);
	//int ad=1;
	//----------------------------------------------------------------------------------------------------------
		
		//string command;
		//printf("count is%d",ac);
		
		//int ad=1;
		//replay = malloc(sizeof(struct redisReply)*num);
    //replies = malloc(sizeof(redisReply*)*num);
    // for (i = 0; i < num; i++)
	// {
		// sprintf(key, "%d_S0E",k);
		// sprintf(value, "{\"real_value\":\"%0.1f\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%0.1f\"}",ac,szTime,ac);
		// if(REDIS_OK!=redisAppendCommand(c,command))
		// {
			// redisFree(c);
		// }
	// }
	
     
    
	// while(1)
	//{
		// timer=0;
		// gettimeofday(&start,NULL);
		// ad=1;
		// szTime = (int)time(NULL);
		// srand(szTime);
		// for (k = 0; k < num; k++)
		// {
			// ac = (Random(m, n) / 10.0);
			// sprintf(key, "%d_S0E",k);
			// sprintf(value, "{\"real_value\":\"%0.1f\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%0.1f\"}",ac,szTime,ac);
			// sprintf(command,"mset %s %s",key,value);
			// printf("command is %s\n",command);
			// if(REDIS_OK!=redisAppendCommand(c,command))
			// {
				// redisFree(c);
			// }
		// }
		// //t1 = usec();
		// for (i = 0; i < num; i++) 
		// {
			// if(REDIS_OK!=redisGetReply(c,(void*)&replies[i]))
			// {
				// printf("Failed to execute command[%s] with Pipeline.\n");  
				// freeReplyObject(replies[i]);  
				// redisFree(c);  
				// //printf("replay is faild!");
			// }
		// }
		// //t2 = usec();
		// for (i = 0; i < num; i++) 
		// {
			// freeReplyObject(replies[i]);
		// }
		// sleep(2);
		// //printf("\t(%dx PING (pipelined): %.3fs)\n", num, (t2-t1)/1000000.0);
		// printf("\n");
		// gettimeofday(&end,NULL);
		// timer = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
		// printf("timer = %ld us\n",timer);
		
	//disconnect(c, 0);
	//}
	num = 10;
    replies = malloc(sizeof(redisReply*)*num);
	while(1)
	{
		timer=0;
		gettimeofday(&start,NULL);
		ad=1;
		szTime = (int)time(NULL);
		srand(szTime);
		//string command;
		ac=1;
		//printf("count is%d",ac);
		//ac = (Random(m, n) / 10.0);
		//int ad=1;
		//----------------------------------------------------------------------------------------------------------
			timer=0;
			gettimeofday(&start,NULL);
			ad=1;
			szTime = (int)time(NULL);
			srand(szTime);
			//string command;
			//printf("count is%d",ac);
			ac = (Random(m, n) / 10.0);
			//int ad=1;
			//replay = malloc(sizeof(struct redisReply)*num);
			for(k=1;k<=10;k++)
			{
				if(k<=10)
				{
					// sprintf(key, "%d_S0E%dA%d",i,j,k);
					// sprintf(value, "{\"real_value\":\"%0.1f\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%0.1f\"}",ac,szTime,ac);
					// key1 = key;
					// value1 = value;
					// sprintf(command,"mset %s %s",key1.c_str(),value1.c_str());
					// reply = (redisReply*)redisCommand(c,command);
					// //printf("PING: %s\n", reply->str);
					// freeReplyObject(reply);
					sprintf(key, "%d_S0E",k);
					sprintf(value, "{\"real_value\":\"%0.1f\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%0.1f\"}",ac,szTime,ac);

					sprintf(command,"mset %s %s",key,value);
					if(REDIS_OK!=redisAppendCommand(c,command))
					{
						redisFree(c);
					}
					
				}
			}
			for(i=0;i<num;i++)
			{
				//assert(redisGetReply(c, (void**)&replay == REDIS_OK));
				if(REDIS_OK!=redisGetReply(c,(void*)&replies[i]))
				{
					printf("Failed to execute command[%s] with Pipeline.\n");  
					freeReplyObject(replies[i]);  
					redisFree(c);  
					//printf("replay is faild!");
				}
				//assert(replay[i] != NULL && replay[i]->type == REDIS_REPLY_STATUS);
			}
			for (i = 0; i < num; i++) 
			{
				freeReplyObject(replies[i]);
			}
		//sleep(2);
		//freeReplyObject(replay);
		printf("\n");
		gettimeofday(&end,NULL);
		timer = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
		printf("timer = %ld us\n",timer);
		
		//delete redis;

	}
	free(replies);
	//redisFree(c);
	redisFree(c);
	//cout << szTime << endl;
	
    //sleep (2);/*休息一秒，延长任务的执行时间*/  
    return NULL;  
}
//static redisContext* c=redisConnect("127.0.0.1",6379);myprocess (void* args)
void *  
myprocess (void* args)  
{  
    //printf ("threadid is, working on task\n"); 
	int area_start=71;
	area_start=*((int *)args);
	printf ("threadid is, working on task %d\n",area_start); 
	int i, j,k,m, n;
	char value[100] = {0};
	char key[50] = {0};
	char command[200] = {0};
	struct  timeval  start;
	struct  timeval  end;
	struct  timeval  start2;
	struct  timeval  end2;
	unsigned long timer;
	//TStrStrMap::iterator p;
	int szTime = (int)time(NULL);
	//srand(szTime);
	m = 200;
	n = 240;
	int num=200000;
	//redisReply *replay=NULL;
	redisReply *replay=NULL;
	redisReply **replies;
	int timeout=10000;
	struct timeval tv;
	tv.tv_sec=timeout/1000;
	tv.tv_usec=timeout*1000;
	float ac;
	int ad;
	redisContext* c=redisConnect("127.0.0.1",6379);
	redisReply *reply;
	if(c->err)
	{
		printf("connect error!\n");
		//return;
	}
	replies = malloc(sizeof(redisReply*) * num);
	while(1)
	{
		timer=0;
		gettimeofday(&start,NULL);
		ad=1;
		szTime = (int)time(NULL);
		srand(szTime);
		//string command;
		ac=1;
		//printf("count is%d",ac);
		//ac = (Random(m, n) / 10.0);
		//int ad=1;
		//----------------------------------------------------------------------------------------------------------
			timer=0;
			gettimeofday(&start,NULL);
			ad=1;
			szTime = (int)time(NULL);
			srand(szTime);
			//string command;
			//printf("count is%d",ac);
			ac = (Random(m, n) / 10.0);
			//int ad=1;
			//replay = malloc(sizeof(struct redisReply)*num);
			for(i=area_start;i<area_start+2;i++)
			{
				for(j=1;j<=200;j++)
				{
					//sprintf(key, "7d%_S0EjA%d",i,j,k);
					for(k=1;k<=500;k++)
					{
						if(k<=300)
						{
							sprintf(key, "%d_S0E%dA%d",i,j,k);
							sprintf(value, "{\"real_value\":\"%0.1f\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%0.1f\"}",ac,szTime,ac);

							sprintf(command,"mset %s %s",key,value);
							if(REDIS_OK!=redisAppendCommand(c,command))
							{
								redisFree(c);
							}
							// sprintf(key, "%d_S0E%dA%d",i,j,k);
							// sprintf(value, "{\"real_value\":\"%0.1f\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%0.1f\"}",ac,szTime,ac);
							// key1 = key;
							// value1 = value;
							// sprintf(command,"mset %s %s",key1.c_str(),value1.c_str());
							// reply = (redisReply*)redisCommand(c,command);
							// //printf("PING: %s\n", reply->str);
							// freeReplyObject(reply);
							
							
							
						}
						else
						{
							sprintf(key, "%d_S0E%dD%d",i,j,k);
							sprintf(value, "{\"real_value\":\"%d\",\"status\":1,\"save_time\":\"%d\",\"display_value\":\"%d\"}",ad,szTime,ad);

							sprintf(command,"mset %s %s",key,value);
							if(REDIS_OK!=redisAppendCommand(c,command))
							{
								redisFree(c);
							}
						}
						
					}
				}
			}
			for(i=0;i<num;i++)
			{
				//assert(redisGetReply(c, (void**)&replay == REDIS_OK));
				if(REDIS_OK!=redisGetReply(c,(void*)&replies[i]))
				{
					printf("Failed to execute command[%s] with Pipeline.\n");  
					freeReplyObject(replies[i]);  
					redisFree(c);  
					//printf("replay is faild!");
				}
				//assert(replay[i] != NULL && replay[i]->type == REDIS_REPLY_STATUS);
			}
			for (i = 0; i < num; i++) 
			{
				freeReplyObject(replies[i]);
			}
		
		//freeReplyObject(replay);
		printf("\n");
		gettimeofday(&end,NULL);
		timer = 1000000 * (end.tv_sec-start.tv_sec)+ end.tv_usec-start.tv_usec;
		printf("timer = %ld us\n",timer);
		sleep(2);
		//delete redis;

	}
	redisFree(c);
	//cout << szTime << endl;
	free(replies);
    //sleep (2);/*休息一秒，延长任务的执行时间*/  
    return NULL;  
}
int main(int argc, char **argv) {
	//myprocess2();
    //unsigned int j;
    //redisContext *c;
    //redisReply *reply;
    // const char *hostname = (argc > 1) ? argv[1] : "127.0.0.1";
    // int port = (argc > 2) ? atoi(argv[2]) : 6379;
	//int processnum;
	//printf ("threadid is, working on task\n");
	int starts;	
	int p1,p2;
	 
	p1=71;
	p2=73;
	starts =0;
	const unsigned int thread_number=4;
	int area_number[NUM_THREADS]={71,73,75,77};
	pthread_t thread1_id[NUM_THREADS];
	int indexes[NUM_THREADS];
	// const unsigned int thread_number=4;
	// 
	// starts =0;
	// int area_number[4]={71,73,75,77};
	// 
	// pthread_t thread1_id2;
	// pthread_create(&thread1_id1, NULL, myprocess2,(void *)&(p1)); 
	// pthread_join(thread1_id1, NULL);
	
	// pthread_create(&thread1_id2, NULL, myprocess,(void *)&(p2)); 
	
	
	// pthread_join(thread1_id2, NULL);
	//start=area_number[0];
	//pthread_create(&thread1_id[0], NULL, myprocess,(void *)&(start)); 
    //pthread_t thread2_id; 
	
	for(p1=0;p1<4;p1++)
	{
		starts=area_number[p1];
		pthread_create(&thread1_id[p1], NULL, myprocess,(void *)&(area_number[p1])); 
		printf("Current pthread id =%s,start is %d\n",thread1_id[p1],area_number[p1]);
	}
	pthread_exit(NULL);
	for (p2 = 0; p2 < NUM_THREADS; ++p2)  
        pthread_join(thread1_id[p2], NULL);
    //pthread_create(&thread2_id, NULL, myprocess,NULL);  
	// for(p2=0;p2<4;p2++)
	// {
		// pthread_join(thread1_id[p2], NULL);
	// }
	// //pthread_exit(NULL);
    return 0;
}
