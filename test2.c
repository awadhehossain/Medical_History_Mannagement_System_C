#include<stdio.h>
#include<string.h>
struct information
{
    char name[30];
    char id[15];
    int age;
    char gender[10];
    char doctor_name[40];
    struct disease
    {
        char problem[30];
    } disease[10];
    struct medicine
    {
        char medi[30];
    } medicine[10];
} info[20];

int arr[10];
int n_arr[10];
void add_information();
void read_info();
int number();
void Update_information(int index);
int main()

{
    int n=1;
    char fn[30];
    while(n!=3)
    {
        printf("Enter 1 for put your ID\n");
        printf("Enter 2 for create account\n");
        printf("Enter 3 for exit\n");
        printf("Enter your choice:");
        scanf("%d",&n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            printf("Enter ID:");
            gets(fn);
            int na=number(),flag=0;
            for(int i=0; i<=na; i++)
            {
                if(strcmp(info[i].id,fn)==0)
                {
                    read_info(i);
                    flag=1;
                }
            }
            if(flag==0)
            {
                printf("Not found\n");
            }
            break;
        case 2:
            add_information();
            break;
        case 3:
            break;
        default :
            printf("Invalid input try again\n");
        }
    }
}


void add_information()
{
    FILE *file=fopen("doctor.txt","a");
    if(file==NULL)
    {
        printf("Error---404");
    }
    else
    {
        int d=number();
        d++;
Line1:
        printf("Enter Your name:");
        gets(info[d].name);
        if(info[d].name[0]=='\0'||strlen(info[d].name)>28)
        {
            goto Line1;
        }
Line2:
        printf("Enter ID:");
        gets(info[d].id);
        if(info[d].id[0]=='\0'||strlen(info[d].id)>14)
        {
            goto Line2;
        }
        printf("Enter age:");
        scanf("%d",&info[d].age);
        fflush(stdin);
Line4:
        printf("Enter Gender:");
        gets(info[d].gender);
        if(info[d].gender[0]=='\0'||strlen(info[d].gender)>9)
        {
            goto Line4;
        }
Line5:
        printf("Enter Doctor name:");
        gets(info[d].doctor_name);
        if(info[d].doctor_name[0]=='\0'||strlen(info[d].doctor_name)>39)
        {
            goto Line5;
        }

        printf("How many disease have found:");
        int num;
        scanf("%d",&num);
        fflush(stdin);
        for(int i=0; i<num; i++)
        {
Line6:
            printf("Enter %d disease:",i+1);
            gets(info[d].disease[i].problem);
            if(info[d].disease[i].problem[0]=='\0' ||strlen(info[d].disease[i].problem)>29)
            {
                goto Line6;
            }

        }

        printf("How many medicine you want to add:");
        int n_num;
        scanf("%d",&n_num);
        fflush(stdin);
        for(int i=0; i<n_num; i++)
        {
Line7:
            printf("Enter %d medicine:",i+1);
            gets(info[d].medicine[i].medi);
            if(info[d].medicine[i].medi[0]=='\0'||strlen(info[d].medicine[i].medi)>29)
            {
                goto Line6;
            }

        }
        fprintf(file,"%d\n",d);
        fprintf(file,"%s\n",info[d].name);
        fprintf(file,"%s\n",info[d].id);
        fprintf(file,"%d\n",info[d].age);
        fprintf(file,"%s\n",info[d].gender);
        fprintf(file,"%s\n",info[d].doctor_name);
        for(int i=num-1; i>=0; i--)
        {
            fprintf(file,"%d\n",i);
            fprintf(file,"%s\n",info[d].disease[i].problem);
        }
        for(int i=n_num-1; i>=0; i--)
        {
            fprintf(file,"%d\n",i);
            fprintf(file,"%s\n",info[d].medicine[i].medi);
        }
    }
    fclose(file);
}

int number()
{
    FILE *file=fopen("doctor.txt","r");
    int index=0;
    char c=' ';
    while(fscanf(file,"%c",&c)!=EOF)
    {

    }
    if(c==' ')
    {
        fclose(file);
        return -1;
    }
    fclose(file);
    file=fopen("doctor.txt","r");
    if(file==NULL)
    {
        printf("Error\n");
    }
    else
    {
        char p;
        char pt[100];
        int i=0,k=0;
        while(fscanf(file,"%d ",&index)!=EOF)
        {

            while ((p = fgetc(file)) != '\n')
            {
                if (p != EOF)
                {
                    pt[i++] = p;
                }
            }
            pt[i] = '\0';
            strcpy(info[index].name,pt);
            i=0;
            while ((p = fgetc(file)) != '\n')
            {
                if (p != EOF)
                {
                    pt[i++] = p;
                }
            }
            pt[i] = '\0';
            strcpy(info[index].id,pt);
            i=0;
            fscanf(file,"%d ",&info[index].age);
            while ((p = fgetc(file)) != '\n')
            {
                if (p != EOF)
                {
                    pt[i++] = p;
                }
            }
            pt[i] = '\0';
            strcpy(info[index].gender,pt);
            i=0;
            while ((p = fgetc(file)) != '\n')
            {
                if (p != EOF)
                {
                    pt[i++] = p;
                }
            }
            pt[i] = '\0';
            strcpy(info[index].doctor_name,pt);
            int flag=0,n;
            while(fscanf(file,"%d ",&n)!='\n')
            {
                i=0;
                if(flag==0)
                {
                    arr[index]=n;
                }
                while ((p = fgetc(file)) != '\n')
                {
                    if (p != EOF)
                    {
                        pt[i++] = p;
                    }
                }
                pt[i] = '\0';
                strcpy(info[index].disease[n].problem,pt);
                flag=1;
                if(n==0)
                {
                    break;
                }
            }
            flag=0;
            i=0;
            int z;
            while(fscanf(file,"%d ",&z)!='\n')
            {
                i=0;
                if(flag==0)
                {
                    n_arr[index]=z;
                }
                while ((p = fgetc(file)) != '\n')
                {
                    if (p != EOF)
                    {
                        pt[i++] = p;
                    }
                }
                pt[i] = '\0';
                strcpy(info[index].medicine[z].medi,pt);
                flag=1;
                if(z==0)
                {
                    break;
                }
            }
            i=0;
        }

    }
    return index;
}


void read_info(int i)
{
    printf("Name       : %s\n",info[i].name);
    printf("ID         : %s\n",info[i].id);
    printf("age        : %d\n",info[i].age);
    printf("Gender     : %s\n",info[i].gender);
    printf("Doctor name: %s\n",info[i].doctor_name);
    printf("disease are: ");
    for(int k=0; k<=arr[i]; k++)
    {
        if(k==0)
        {
            printf("%s",info[i].disease[k].problem);
        }
        else
        {
            printf(",%s",info[i].disease[k].problem);
        }
    }
    printf("\nMedicine are: ");
    for(int k=0; k<=n_arr[i]; k++)
    {
        if(k==0)
        {
            printf("%s",info[i].medicine[k].medi);
        }
        else
        {
            printf(", %s",info[i].medicine[k].medi);
        }
    }
    printf("\n\n");
    int e;
    printf("if You any change of data enter 1\n");
    printf("If you don't want to change data enter 2\n");
    scanf("%d",&e);
    fflush(stdin);
    if(e==1)
    {
        Update_information(i);
    }
    else
    {
        return;
    }
}

void Update_information(int index)
{
    int N_index=number();
    printf("Change Doctor name for enter 1\n");
    printf("Change disease enter 2\n");
    printf("Change Medicine enter 3\n");
    int n;
    scanf("%d",&n);
    fflush(stdin);
    char input[100];
    switch(n)
    {
    case 1:
line1:
        printf("Enter doctor name:");
        gets(input);
        strcpy(info[index].doctor_name,input);
        if(info[index].doctor_name[0]=='\0'||strlen(info[index].doctor_name)>39)
        {
            goto line1;
        }
        break;
    case 2:
        printf("enter 1 for Add disease \n ");
        printf("enter 2 for delete disease \n ");
        printf("Enter 3 for update disease\n");
        printf("Enter 4 for not change any data\n");
        printf("Enter your choice:");
        int line;
        scanf("%d",&line);
        fflush(stdin);
        if(line==3)
        {
            for(int i=0; i<=arr[index]; i++)
            {
                printf("change %s  for %d\n",info[index].disease[i].problem,i+1);
            }

            scanf("%d",&n);
            fflush(stdin);
            printf("Enter new disease :");
line2:
            gets(input);
            strcpy(info[index].disease[n-1].problem,input);
            if(info[index].disease[n-1].problem[0]=='\0'||strlen(info[index].disease[n-1].problem)>29)
            {
                goto line2;
            }
        }
        else if(line==4)
        {
            return ;
        }
        else if(line==1)
        {
line4:
            arr[index]+=1;
            printf("Enter new disease :");
            gets(input);
            strcpy(info[index].disease[arr[index]].problem,input);
            if(info[index].disease[arr[index]].problem[0]=='\0'||strlen(info[index].disease[arr[index]].problem)>29)
            {
                goto line4;
            }
        }
        else if (line==2)
        {

line5:

            printf("Enter delete disease position :");
            int pos;
            scanf("%d",&pos);
            fflush(stdin);
            int flag=0;
            if(pos>0&&arr[index]>=pos)
            {
                for(int i=pos-1; i>=arr[index]-1; i--)
                {
                    strcpy( info[index].disease[i].problem,info[index].disease[i+1].problem);
                }
                arr[index]-=1;
            }
            else
            {
                goto line5;
            }

        }


        break;
    case 3:
        printf("enter 1 for Add medicine \n ");
        printf("enter 2 for delete medicine \n ");
        printf("Enter 3 for update medicine\n");
        printf("Enter 4 for not change any data\n");
        printf("Enter your choice:");
        int lin;
        scanf("%d",&lin);
        fflush(stdin);
        if(lin==3)
        {
            for(int i=0; i<=n_arr[index]; i++)
            {
                printf("change %s  for %d\n",info[index].medicine[i].medi,i+1);
            }

            scanf("%d",&n);
            fflush(stdin);
            printf("Enter new medicine :");
line21:
            gets(input);
            strcpy(info[index].medicine[n-1].medi,input);
            if(info[index].medicine[n-1].medi[0]=='\0'||strlen(info[index].medicine[n-1].medi)>29)
            {
                goto line21;
            }
        }
        else if(lin==4)
        {
            return ;
        }
        else if(lin==1)
        {
line41:
            n_arr[index]+=1;
            printf("Enter new medicine :");
            gets(input);
            strcpy(info[index].medicine[n_arr[index]].medi,input);
            if(info[index].medicine[n_arr[index]].medi[0]=='\0'||strlen(info[index].medicine[n_arr[index]].medi)>29)
            {
                goto line41;
            }
        }
        else if (lin==2)
        {



line51:
            printf("Enter delete medicine position :");
            int pos;
            scanf("%d",&pos);
            fflush(stdin);
            int flag=0;
            if(pos>0&&n_arr[index]>=pos)
            {
                for(int i=pos-1; i>=n_arr[index]-1; i--)
                {
                    strcpy( info[index].medicine[i].medi,info[index].medicine[i+1].medi);
                }
                n_arr[index]-=1;
            }
            else
            {
                goto line51;
            }
        }
        break;
    }
    FILE *file=fopen("doctor.txt","w");
    for(int i=0; i<=N_index; i++)
    {
        fprintf(file,"%d\n",i);
        fprintf(file,"%s\n",info[i].name);
        fprintf(file,"%s\n",info[i].id);
        fprintf(file,"%d\n",info[i].age);
        fprintf(file,"%s\n",info[i].gender);
        fprintf(file,"%s\n",info[i].doctor_name);
        for(int j=arr[i]; j>=0; j--)
        {
            fprintf(file,"%d\n",j);
            fprintf(file,"%s\n",info[i].disease[j].problem);
        }
        for(int j=n_arr[i]; j>=0; j--)
        {
            fprintf(file,"%d\n",j);
            fprintf(file,"%s\n",info[i].medicine[j].medi);
        }
    }
    fclose(file);
}
