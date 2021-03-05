inherit F_CLEAN_UP;
#define unusedvar_log_file "/log/log.var"
string file,*f_line,new_f_line,chk,unusedvar;
string wfile,*wf_line, lastw;
string filename,argv_name,c1,c2;

int start,line_n;
	
int check(int s);
int check1();
int clean(string line);
int isdata(string s);//对这一行简单分析,判断是否是数据定义行
int peidui(string s);//对这一行简单分析,判断([{}])是否残缺
int main(object me, string arg)
{	
	string *founded;//已经出现过的错误
	unusedvar="";
	new_f_line="";
	if(!arg)arg="/log/log";
	if(file_size(arg)==-1) 
		{write(arg+"文件不存在。\n");return 0; }	
	if(!file = read_file(arg)||sizeof(file)==0)
		{write("无法读取该文件："+arg+"\n");return 0; }

	f_line = explode(file,"\n");
		write_file(arg,"",1);
	founded=({});
	lastw="";//上一个错误文件名
	foreach(chk in f_line) //chk log file each line
	{
		if(sscanf(chk,"%s line %d: Warning: Unused local variable '%s'",filename,line_n,argv_name)==3)
		{	
			unusedvar+=chk+"\n";
			if(member_array(chk,founded)!=-1)continue;//this mistake have be treated 
			founded+=({chk});
			if(lastw!=filename)                              //新文件有错
			{if(lastw!="")
				{	write_file(lastw,implode(wf_line,"\n"),1);    //先保存修改老文件
					unusedvar+="----write_file name=="+lastw+" end.....\n\n";					
				}
			lastw=filename;	
			if(!wfile = read_file(filename))        //再读新文件
				{write("无法读取该文件："+filename+"\n");return 0; }
			wf_line = explode(wfile,"\n");	//wrong file lines
			
			}//否则接着修改刚才的文件，以免重复打开修改存盘同一文件
			unusedvar+="┏"+filename+" @line="+line_n+", Unused variable="+argv_name+"\n"; 
			
			if(line_n>=sizeof(wf_line))line_n=sizeof(wf_line)-1; // 有些文件行数有问题,\n打断会少一二行
			
			while(line_n>=0) 
			{	
				if(isdata(wf_line[line_n]))
				{	//write("line_n number=="+(line_n+1)+"    argv_name is "+argv_name +"\n");
					start=0;
					if(check(start)) //找到并修改成功
					 break;
				}	
				line_n--;
			}
		}   //  /d/dntg/sky/stars/23.c line 3: Cannot #include star.c before the end of file
		else if(sscanf(chk,"%s line %d: Cannot #include %s before",filename,line_n,argv_name)==3)
		{	
			unusedvar+=chk+"\n";
			if(member_array(chk,founded)!=-1)continue;//this mistake have be treated 
			founded+=({chk});
			if(lastw!=filename)                              //新文件有错
			{if(lastw!="")
				{	write_file(lastw,implode(wf_line,"\n"),1);    //先保存修改老文件
					unusedvar+="----write_file name=="+lastw+" end.....\n\n";					
				}
			lastw=filename;	
			if(!wfile = read_file(filename))        //再读新文件
				{write("无法读取该文件："+filename+"\n");return 0; }
			wf_line = explode(wfile,"\n");	//wrong file lines
			
			}//否则接着修改刚才的文件，以免重复打开修改存盘同一文件
			unusedvar+="┏"+filename+" @line="+line_n+", Cannot #include="+argv_name+"\n"; 
			
			if(line_n>=sizeof(wf_line))line_n=sizeof(wf_line)-1; // 有些文件行数有问题,\n打断会少一二行
			
			while(line_n>=0) 
			{
				if(strsrch(wf_line[line_n],"<"+argv_name+">")!= -1)
				{	//write("line_n number=="+(line_n+1)+"    argv_name is "+argv_name +"\n");
					//start=0;
					check1(); //找到并寻找文件尝试修改
					 break;
				}	
				line_n--;
			}
		}
		else new_f_line=new_f_line+chk+"\n";
		
		
	}
	if(lastw!="") write_file(lastw,implode(wf_line,"\n"),1);
	if(lastw!="")unusedvar+="-----------write file name=="+lastw+" end.....\n"; 
		else unusedvar+="\n-----------no file found Unused local variable or cannot be included file. end.....\n";
	write_file(unusedvar_log_file,unusedvar,1);
	write_file(arg,new_f_line);//不认识的写回原log文件
	write("ok.check "+unusedvar_log_file+" for examination。\n");
	return 1; 
}
int isdata(string s)//对这一行简单分析,判断是否是数据定义行
{
	string chk,*leixing=({"int","string","object","mapping","mixed","float","buffer"});//class,array 很少有，定义了不用可能性极小
	int n;
	foreach(chk in leixing)
	{
		if((n=strsrch(s,chk)) != -1) 
		{
			if(n!=0&&s[n-1]!=' '&&s[n-1]!='\t'&&s[n-1]!=';') // 类型名称前面总得是空白吧
				return 0;
			n+=sizeof(chk);
			if(s[n]==' '||s[n]=='*'||s[n]=='/'||s[n]=='\t') //有些定义数组是在类型后面加*，或某些变量已经注释引起无法确实类型名称
				return 1;
		}
	}
	return 0;
}

int check(int s)//对这一行详细分析, 是否有未使用变量并修改
{	
	int temp; //记录变量字符串位置，符号配对性，防止有人开始定义变量时进行函数调用复杂的多变量初始化
	start=s;   
	if((temp=strsrch(wf_line[line_n][s..],argv_name)) != -1) //检查前后字符，看是否有这个变量
	{	start+=temp;//开始位置		
		c1=wf_line[line_n][start-1..start-1];
		//write("111argv_name is "+argv_name +" c1 is "+c1+"\n");
		if(member_array(c1,({" ",",","*","/","\t"}))==-1)
			return check(start+sizeof(argv_name));//前面不是空格或逗号或星号，应该不是变量，检查后面可能有这个变量
		//write("111\n");
		c2=wf_line[line_n][start+sizeof(argv_name)..start+sizeof(argv_name)];
		if(member_array(c2,({" ",",",";","=","/","\t"}))==-1)//后面不是空格或逗号或分号，应该不是变量，检查后面可能有这个变量
			return check(start+sizeof(argv_name));
		while(member_array(c1,({" ",",","*","/","\t"}))!=-1)
		{	//write("left argv_name is "+argv_name +" c1 is "+c1+"\n");
			if(c1=="/")break;
			argv_name=c1+argv_name;start--; 
			c1=wf_line[line_n][start-1..start-1];
		}		 
		while(1)
		{
			if(peidui(argv_name)==1) 
			{//write("right argv_name is "+argv_name +" c2 is "+c2+"\n");
				if(c2==";" ||c2=="/"|| c2==",")  //一定要结束
				{if(strsrch(argv_name,",")==-1)//没有逗号，说明是第一个变量，需要消除后面的，
					if(c2==",") argv_name=argv_name+c2;
				break;
				}
			}
			argv_name=argv_name+c2;
			c2=wf_line[line_n][start+sizeof(argv_name)..start+sizeof(argv_name)];
		}
		if(argv_name[0..1]=="* "||argv_name[0..1]=="*\t")argv_name=argv_name[1..];//防止有人把*写在类型后面的习惯
		if(argv_name[0..0]==" "||argv_name[0..0]=="\t")argv_name=argv_name[1..];//防止已有的注释把/*写在类型后面,导致无法识别类型
		unusedvar+="┣the wrong is "+"@line"+(line_n+1)+"『"+wf_line[line_n]+"』\n";
		wf_line[line_n]=wf_line[line_n][0..start-1]+replace_string(wf_line[line_n][start..],argv_name,"/*"+argv_name+"*/",1);//注释掉变量
		
		clean(wf_line[line_n]);
		return 1;
	}
	
	return 0;
}
int check1()//检查同目录下是否与这个include文件
{	
   
	string dir;
	dir=filename[0..strsrch( filename, "/",	-1)];
	if (member_array(argv_name,get_dir(dir))==-1)	//当前目录下没有这个文件
	unusedvar+="┣the wrong is "+"@line"+(line_n+1)+"『"+wf_line[line_n]+"』,cannot find the "+argv_name+" in the same dir.\n";
	else
	{unusedvar+="┣the wrong is "+"@line"+(line_n+1)+"『"+wf_line[line_n]+"』\n";
	 wf_line[line_n]=replace_string(wf_line[line_n],"<"+argv_name+">","\""+argv_name+"\"",1);//改为include 本目录下文件	
	 unusedvar+="┗the corrected line"+(line_n+1)+"『"+wf_line[line_n]+"』\n";
	}
		return 1;
}

int clean(string line)  //clean so much *//* together,and type name alone
{
	string f,s1,s2,*fs;
	wf_line[line_n]=replace_string(wf_line[line_n],"*//*","");//clean so much *//* together,00
	wf_line[line_n]=replace_string(wf_line[line_n],"*/ /*","");
	f=wf_line[line_n]+"";
	f=replace_string(f,"\t"," ");
	while(sscanf(f,"%s/*%*s*/%s",s1,s2)==3)f=s1+" "+s2;
	 sscanf(f,"%s//%*s",f);	 
	fs= explode(f," ");	
	fs-=({"",";","{"});

	if(sizeof(fs)<2)
	{	wf_line[line_n]=replace_string(wf_line[line_n],"/*","");
		wf_line[line_n]=replace_string(wf_line[line_n],"*/","");
		wf_line[line_n]=replace_string(wf_line[line_n]," ;",";");
		
		if(strsrch(wf_line[line_n],"{")!=-1)
			wf_line[line_n]=replace_string(wf_line[line_n],"{","{ //",1);
		else wf_line[line_n]="//"+wf_line[line_n];
		wf_line[line_n]=replace_string(wf_line[line_n],"//  ","//");		
	}
	 unusedvar+="┗the corrected line"+(line_n+1)+"『"+wf_line[line_n]+"』\n";
}

int peidui(string arg)//from nt7,对这一行简单分析,判断([{}])是否残缺
{
        int idx, chr, mark, marked;
        int s_symbol, m_symbol, b_symbol, d_quote, s_quote;
		idx=0; chr=0; mark=0; marked=0;
       s_symbol=0; m_symbol=0; b_symbol=0; d_quote=0; s_quote=0;
                for(idx=0; idx<strlen(arg); idx++)
                {
                        chr = arg[idx];
                        mark = (chr == '\\');
                        if( mark ) marked++;
                        if( !(s_quote%2) && (!marked || !(marked%2)) && chr == '\"' ) d_quote++;
                        if( !(d_quote%2) && (!marked || !(marked%2)) && chr == '\'' ) s_quote++;
                        if( !mark ) marked = 0;
                        if( d_quote%2 ) continue;
                        switch(chr)
                        {
                        case '(':       s_symbol++;     break;
                        case ')':       s_symbol--;     break;
                        case '[':       m_symbol++;     break;
                        case ']':       m_symbol--;     break;
                        case '{':       b_symbol++;     break;
                        case '}':       b_symbol--;     break; 
                        }
                }

        if( d_quote%2||s_quote%2||s_symbol||m_symbol|| b_symbol)return 0;
		return 1;
}

int help (object me)
{
        write(@HELP
    自动注释掉源文件中所有mudos或fluffos发现的未使用的变量，
修改 #include <本目录下文件>  为  #include "本目录下文件";
以节约内存，注释后的文件记录会从log文件中删除，以减小log文
件，其它不认识的错误会写回原log文件.以方便巫师查错。
    已经注释的文件另给一个记录，默认文件名为/log/log.var
前面是log文件本身，后面是修改情况正常情况开始会形成三行封闭
的制表符，以方便判断是否注释正确。
		
指令格式：chklog [logfile]
没有 logfile，则logfile默认为 log/log 
HELP
        );
        return 1;
}

























