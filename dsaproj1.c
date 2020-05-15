/*Music Playlist Editor By Rohin Vaidya and Shivam Yadav - Fr. Conceicao Rodrigues College Of Engineering ,Bandra,Mumbai,India */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
struct song
{
char title[15];
char artist[10];
float duration;
};

struct song_node
{
struct song s;
struct music *next;
struct music *prev;
};

struct song_node *create_song()
{
  float d;
  struct song_node *newnode;
  newnode=(struct song_node *)malloc(sizeof(struct song_node));
  printf("Enter title and artist\n");
  scanf("%s %s",newnode->s.title,newnode->s.artist);
  printf("Enter duration of song\n");
  scanf("%f",&d);
  newnode->s.duration=d;
  newnode->next=newnode->prev=NULL;
  return (newnode);
}

struct song_node *defaultplay(struct song_node *head)
{
  int i;
  struct song s1[5]={{"KYE","Green Day",5.0},{"AI","Green Day",5.5},{"Faded","A. Walker",6.0},{"Spectre","Alan Walker",4.0},{"Shelter","Porter R.",6.3}};
  printf("\nPlease enter the first song\n");
  head=create_song();
  struct song_node *temp;
  temp=(struct song_node *)malloc(sizeof(struct song_node));
  temp=head;
  for (i=0;i<5;i++)
  {
    struct song_node *newnode;
    newnode=(struct song_node *)malloc(sizeof(struct song_node));
    strcpy(newnode->s.title,s1[i].title);
    strcpy(newnode->s.artist,s1[i].artist);
    newnode->s.duration=s1[i].duration;
    newnode->prev=temp;
    temp->next=newnode;
    temp=temp->next;
  }
  return(head);
}

void display(struct song_node *head)
{
    struct song_node *temp;
    temp=(struct song_node *)malloc(sizeof(struct song_node));
    temp=head;
    while (temp!=NULL)
    {
        printf("\nTitle: %s\n",temp->s.title);
        printf("Artist: %s\n",temp->s.artist);
        printf("Duration: %f\n",temp->s.duration);
        temp=temp->next;
    }
}

/*struct song_node *shuffle(struct song_node *head)
{
    struct song so;
	int i,sh1,sh2,count,n;
	i=1;sh1=1;sh2=5;
	count=1;
	n=no_of_songs(head);
	struct song_node *temp1,*temp2;
	temp1=temp2=head;
	while(i<n/2)
	{
	while(count<=sh1)
    {
        temp1=temp1->next;
        count++;
    }
    count=1;
    while(count<=sh2)
    {
        temp2=temp2->next;
        count++;
    }
    so=temp1->s;
    temp1->s=temp2->s;
    temp2->s=so;
	i++;sh1++;sh2--;
    }
    display(head);
    return(head);
}
*/
void play(struct song_node *head)
{
    int i,count;
    i=1;
    struct song_node *t;
    t=(struct song_node *)malloc(sizeof(struct song_node));
    t=head;
    printf("\nHow many songs would you like to play?\n");
    scanf("%d",&count);
    while(i<=count)
    {
    printf("\nTitle: %s\n",t->s.title);
    printf("Artist: %s\n",t->s.artist);
    printf("Time Elasped: %f\n",t->s.duration);
    t=t->next;
    i++;
    }
}

void play_previous(struct song_node *head)
{
    struct song_node *t1;
    t1=(struct song_node *)malloc(sizeof(struct song_node));
    t1=head;
    while(t1!=NULL)
    {
       printf("\nTitle: %s\n",t1->s.title);
        printf("Artist: %s\n",t1->s.artist);
        printf("Duration: %f\n",t1->s.duration);
        t1=t1->prev;
    }
}

int no_of_songs(struct song_node *head)
{
    int count=0;
    struct song_node *tmp;
    tmp=(struct song_node *)malloc(sizeof(struct song_node));
    tmp=head;
    while(tmp!=NULL)
    {
        tmp=tmp->next;
        count++;
    }
    return(count);
}

struct song_node *insert_begin(struct song_node *head)
{
    struct song_node *temp,*newnode;
    temp=(struct song_node *)malloc(sizeof(struct song_node));
    newnode=(struct song_node *)malloc(sizeof(struct song_node));
    temp=head;
    newnode=create_song();
    newnode->next=temp;
    temp->prev=newnode;
    head=newnode;
    return (head);
}

struct song_node *insert_end(struct song_node *head)
{
    struct song_node *temp,*newnode;
    temp=(struct song_node *)malloc(sizeof(struct song_node));
    newnode=(struct song_node *)malloc(sizeof(struct song_node));
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    newnode=create_song();
    newnode->prev=temp;
    temp->next=newnode;
    newnode->next=NULL;
    return(head);
}

struct song_node *insert_at_position(struct song_node *head,int p)
{
    struct song_node *newnode,*temp;
    temp=(struct song_node *)malloc(sizeof(struct song_node));
    newnode=(struct song_node *)malloc(sizeof(struct song_node));
    temp=head;
    newnode=create_song();
    int pos;
    pos=1;
    while(pos<p)
    {
        temp=temp->next;
        pos++;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    return(head);
}

struct song_node *remove_begin(struct song_node *head)
{
    struct song_node *temp;
    temp=(struct song_node *)malloc(sizeof(struct song_node));
    temp=head;
    head=temp->next;
    head->prev=NULL;
    return(head); 
}

struct song_node *remove_end(struct song_node *head)
{
    struct song_node *previous,*temp;
    temp=(struct song_node *)malloc(sizeof(struct song_node));
    temp=head;
    while(temp->next!=NULL)
    {
        previous=temp;
        temp=temp->next;
    }
    previous->next=NULL;
    temp->next=temp->prev=NULL;
    return(head);   
}

struct song_node *remove_at_position(struct song_node *head,int p)
{
    int pos;
    pos=1;
    struct song_node *previous,*temp;
    temp=(struct song_node *)malloc(sizeof(struct song_node));
    temp=head;
    while(pos<=p)
    {
        previous=temp;
        temp=temp->next;
        pos++;
    }
    previous->next=temp->next;
    temp->next=NULL; 
    return(head);
}

int main()
{
int ch,i,x,y;
struct song_node *head;
head=(struct song_node *)malloc(sizeof(struct song_node));
head=defaultplay(head);
printf("\n\t\t\t*****Default Playlist Has Been Created*****\n");
while (1)
{
  printf("\n\t\t\t******Choose Your Operation******\n\t\t\t\t1.Display Playlist\n\t\t\t\t2.Shuffle Playlist\n\t\t\t\t4.Number of songs in the playlist\n\t\t\t\t5.Play Music\n\t\t\t\t6.Insert new song\n\t\t\t\t7.Remove a song\n\t\t\t\t8.Exit\n");
  scanf("%d",&ch);
  switch(ch)
    {
      case 1:display(head);
            break;
      case 2://head=shuffle(head);
            break;
      case 3:break;
      case 4:x=no_of_songs(head);
            printf("Total Songs: %d\n",x);break;                
      case 5: play(head);break;
      case 6:
            printf("\nWhere would you like to insert new song?\n\t1.At the start\n\t2.At the end\n\t3.At a position\n");
            scanf("%d",&y);
            switch(y)
            {
                case 1:head=insert_begin(head);break;
                case 2:head=insert_end(head);break;
                case 3:printf("\nEnter position at which song should be entered\n");
                        scanf("%d",&i);
                        head=insert_at_position(head,i);break;
            }
            break;
      case 7:printf("\nWhich song would you like to delete?\n\t1.First\n\t2.Last\n\t3.At a position\n");
            scanf("%d",&y);
            switch(y)
            {
                case 1:head=remove_begin(head);break;
                case 2:head=remove_end(head);break;
                case 3:printf("\nEnter position at which song should be deleted\n");
                        scanf("%d",&i);
                        head=remove_at_position(head,i);break;
            }break;
      case 8:printf("\n\t\t\t\t*****Thank you for using our application*****\n");exit(0);
    }
}
}


// End of the code copyrights Shivam and Rohin FRCRCE,Bandra,Mumbai,India @ 2018 