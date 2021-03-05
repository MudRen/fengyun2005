// Room: /u/mon/poem/clubpoem by mon@xyj 7/25/97
//		--- Modified from one xyj version by silencer@fy4.
// 明月对词版^o^ annie 1.1.2005

inherit ROOM;
#include <ansi.h>;
int POEMS=2;
string author,title,*poem;
string author1,title1,*poem1;
string current,last;
string curr_show;
int length,length1,running;
int index,chance;
int poem_index,answerd,ans_curr,ans_last;
void new_poem();
void copy_to_old();
void do_test();
void do_init(object me);
void poem_reward(object me,string arg);
void poem_reward1(object me);
void poem_penalty(object me);
int find_newline();
string mixup(string str);
string enscript(string arg);

void create ()
{
    set ("short", "青云楼");
    set ("long", @LONG
登上青云诗社二楼，风云城的繁华景象尽收眼底，东窗外是天坛，不时有进宫
的车马行过。这里永远是热热闹闹的，锦衣的公子哥们儿，布衣的酸秀才们，都喜
欢聚在这里品茶吟诗，谈古论今，就连端茶送菜的小二哥也能出口成章。最近这儿
来了个秀才，最喜欢与人对诗，还在柜台上新贴了张[33m启事[32m。
LONG);
    set("exits",  ([  /*  sizeof()  ==  1  */
	"down"  :  __DIR__"shishe",
      ]));
    set("objects", ([
	__DIR__"npc/suanxiucai": 1,
      ]));
    set("coor/x",-20);
    set("coor/y",60);
    set("coor/z",10);
    set("map","fynorth");
    set("file","/data/poem/poem3");
    setup();
    remove_call_out("do_test");
    remove_call_out("do_test1");
    poem_index=-1;
    running=0;
}

void do_test1()
{
	tell_room(this_object(), CYN"酸秀才摇头晃脑吟道：逝水逐残月，时砂无与多。\n"NOR);
	call_out("do_test",10);
}

void init()
{   
    add_action("do_answer","answer");
    add_action("do_look","look");    
    //    	call_out("do_init",1,this_player());
    if(running==0) {
	running=1;
	new_poem();
	copy_to_old();
	new_poem();
	do_test();
//	call_out("do_test",2);
    }
}
/*
void do_init(object me)
{ 
	return;
}*/
int do_answer(string arg)
{ 
    object me=this_player(),ob;
    if(!arg) return notify_fail("你想回答什么？\n");
    if(me->is_busy())
	return notify_fail("你还是先把手头的事儿忙完吧。\n");
    if(me->query_temp("poemok")>50 && me->query("timer/last_poem")+ 300 > time() )
	return notify_fail("酸秀才说：阁下饱读经书，学富五车，请休息片刻，我再想几个难的！!\n");

//	me->set("timer/annie_poem_failed",time());
	if (me->query("timer/annie_poem_failed")+ 300 > time())
	{
		poem_penalty(me);
		return 1;
	}
    /*   	if( me->query("gin")<me->query("max_gin")/20 
		   || me->query("eff_gin")<me->query("max_gin")/20 )
		   return notify_fail("你的精不够了。\n");
	   if(living(me) ) 
		   me->receive_damage("gin",5+random(15),"读书过度心力交瘁暴卒。");*/
    if(objectp(ob=present("suan xiucai",this_object()))
      && living(ob)) {
	switch(random(2)) {
	case 0: message_vision("$N说道：是．．．"+arg+"？\n",me);
	    break;
	case 1: message_vision("$N答道："+arg+"？\n",me);
	    break;
	}
	// check cheat here..grin
	if (sizeof(arg) < sizeof(current) -2 || sizeof(arg) > sizeof(current) +2 )
	{
	    me->add_temp("poem/wrong",10);
			if(me->query_temp("poem/wrong")>20) 
				poem_penalty(me);
		if (environment(me) != this_object())
			return 1;
	}





	if(arg==current && sizeof(current)>2) {
	    if(ans_curr==1) {
		write("别人已经回答过这句诗了。\n");
		return 1;
	    }

	    ans_curr=1;
	    //change to a new poem once this one is answered.
	    index=length-1;
	    me->set_temp("poem/index",poem_index);

	current=replace_string(current," ","");
	current=replace_string(current,",","");
	current=replace_string(current,"，","");
	current=replace_string(current,"。","");
	current=replace_string(current,"！","");
	current=replace_string(current,"？","");

	    poem_reward(me,current);
	} else if(arg== last && sizeof(last)>2) {
	    if(ans_last == 1) {
		write("别人已经回答过这句诗了。\n");
		return 1;
	    }
	    ans_last=1;

	last=replace_string(last," ","");
	last=replace_string(last,",","");
	last=replace_string(last,"，","");
	last=replace_string(last,"。","");
	last=replace_string(last,"！","");
	last=replace_string(last,"？","");

	    poem_reward(me,last);
	} else {
	    message_vision("酸秀才摇了摇头：好象不对吧？\n",me);
		if (!random(3))
		    me->add_temp("poem/wrong",1);
		if(me->query_temp("poem/wrong")>20) 
			poem_penalty(me);
	}
    } else {
	write("酸秀才不在，没有人裁判对错了．．． ：（\n");
    }
    return 1;
}
void poem_penalty(object me)
{
	object r;
    message_vision(HIW"酸秀才摇头道：知之为知之，不知为不知，方是知也。\n",me);
    message_vision(HIR"酸秀才道：去，去，去。\n",me);
    message_vision(MAG"酸秀才挥挥袖子，$N腾云驾雾般地从青云楼上飞了出去。\n"NOR,me);
    me->set_temp("poem/wrong",0);
	r=find_object("/d/fy/jssju2");
	if (!r)
		r=load_object("/d/fy/jssju2");
	me->move(r);
    message_vision(HIG"只听得哗啦一声，一个人影撞开了顶楼的纸窗，重重地砸在墙上。\n"NOR,me);
	me->unconcious();
	me->set("timer/annie_poem_failed",time());
    return;
}
void poem_reward(object me,string arg)
{
    me->set_temp("poem/wrong",0);
    message_vision(CYN"酸秀才点头道：答对了，不错！不错！\n"NOR,me);
    me->add_temp("poemok",1);
    poem_reward1(me);
}
void poem_reward1(object me)
{  
    int dx,pot,lite;
    
    if (!me->query_skill("literate",1))
    	me->set_skill("literate",1);
    
    // 1 answer = 1 level, only need 11 answer to full ( read huangshan stone first)	
    lite = me->query_skill("literate",1)*8000;
    
    if (me->query_skill("literate",1) <= 60) {
	me->improve_skill("literate",lite);
	//	     		me->add("jing",-me->query("eff_jing")/20);
	//             		me->add("eff_jing",-me->query("max_jing")/20);
	write("你的读书识字进步了！\n");
    }
    me->add("poem_answered",1);
    if (QUESTS_D->verify_quest(me,"对诗") && me->query_temp("poemok")>=3) {
	me->delete_temp("poemok");
	QUESTS_D->special_reward(me,"对诗");
    }    	
    //    	dx=me->query("poem_answered");
}
void do_test()
{  
    int newt;
    object ob;
//    string first,second,quest;
	string* poemstr,quest,first,second;
	int ann1,ann2,ann3;
    if(objectp(ob=present("suan xiucai",this_object()))
      && living(ob)) {
	if(sizeof(current)>2 && ans_curr==0) {
	    last=current;
//	    last_all=current_all;
	    ans_last=0;
	}
	newt=0;
	while(newt==0) {


		index = random(sizeof(poem));
//		write("11"+sizeof(poem));
			ann1=strsrch(poem[index],"，");
			ann2=0;
			ann3=0;
			poemstr = ({});

			while (ann1 > 0)
			{
				ann3++;
				poemstr += ({ poem[index][ann2..ann1-1]+"，" });
				poem[index]=poem[index][ann1+1..];
				ann1=strsrch(poem[index],"，");
			}
               
			poemstr+=({poem[index]});

			newt=1;
			// 在这里写合并程式；
			ann2=0;
			for (ann1=0;ann1<sizeof(poemstr) ; ann1++)
			{
				if (sizeof(poemstr[ann1]) < 15 && ann1 != sizeof(poemstr)-1)
				{
					poemstr[ann1]+=poemstr[ann1+1];
//					write(HIY+poemstr[ann1]+NOR+"\n");
					ann2++;
					poemstr[ann1+1]="";
				}
			}
			for (ann1=0;ann1<ann2 ; ann1++)
				poemstr-=({""});
//			write(poemstr[0]+"\n");
//			write(poemstr[1]+"\n");
//			write(poemstr[2]+"\n");
/*
			if(sscanf(poem[index],"%s  %s",first,second)==2 &&
			  !sscanf(poem[index],"%*s［") && 
			  !sscanf(poem[index],"%*s（") &&
			  !sscanf(poem[index],"%*s□") )
			{
				if(strlen(first)>2&&strlen(second)>2)
					newt=1;
			}*/
//	    }
	}
//	current_all=first+"  "+second;
	ans_curr=0;
	ann1=random(sizeof(poemstr));
	quest=poemstr[ann1];

	if (sizeof(quest) < 13 && ann1 > 0)
		quest = poemstr[ann1-1]+quest;
		
//	current=replace_string(quest,"，","");  // the answer
	current=quest;	// 要求标号位置正确
	
	quest=mixup(quest);   // the question
	quest=mixup(quest);   // the question
	curr_show=quest;
	tell_room(this_object(), enscript("酸秀才提笔在墙上写道："+quest)+"\n");
    }
    if(sizeof(filter_array(all_inventory(this_object()), (:userp:))))
		call_out("do_test1",55);
    else
	running=0;
    return;
}
string mixup(string str)
{
    int len=sizeof(str),i,j,k,l;
    string ans;
    for(i=1;i<=random(2)+1;i++) {
	j=random(len);
	k=random(len);
	if(j==k) {
	    k++;
	    if(k>=len) k=0;
	}
	if(j>k) {
	    l=k; k=j; j=l;
	} // so j<k
	j=j+j; k=k+k;
	if(j>0) 
	    ans=str[0..j-1]; 
	else 
	    ans="";
	ans+=str[k..k+1]+str[j+2..k-1]+str[j..j+1];
	if(k<len+len-2) 
	    ans+=str[k+2..len+len-1];
	str=ans;
    }
    return str;
}
int do_look(string arg){   
    int i;
    if(!arg) return 0;
    if(arg=="wall")
	{
	if (wizardp(this_player()))
		write(CYN"当前的答案是："+current+"\n"NOR);
//	for (i=0;i<length1;i++)	    write("    "+poem1[i]+"\n");
	write("\n\n");
	write(WHT"当前题目：　　　"+curr_show+"\n"NOR);
	return 1;
    } else if(arg=="启事") {
	write("\n"+@LONG
           本社新增猜诗游戏，由酸秀才将一句诗词的若干字
       颠倒次序，写在墙上。能准确答出(answer)原句者为胜。
       要想知道当前题目，可以往墙上(wall)看。
       例如：酸秀才提笔在墙上写道：离离原上草一荣一枯岁
       你应该回答：answer 离离原上草一岁一枯荣
LONG);
	write("\n");
	return 1;
    } else 
	return 0;
}
void copy_to_old()
{    int i;
    object ob;
    length1=length;
    poem1=({});
    last="";
    for (i=0;i<length;i++)
	poem1+=({poem[i]});
    if(objectp(ob=present("suan xiucai",this_object()))
      && random(2)==7 && living(ob)) {
	message_vision(({ob->name()+"摇头晃脑地吟诵道：",
	    ob->name()+"高声朗读道：",
	    ob->name()+"仿佛在自言自语："})[random(3)]+"\n",ob);
	for (i=0;i<length1;i++) {
	    message_vision("    "+poem1[i]+"\n",ob);
	}
	message_vision("\n",ob);
    }
    return;
}
void new_poem()	{   
    string filename,buf;
    int i,j,k;

	string *line,lines;
    length=0;




		filename=query("file");
		k=1;
		i=0;
		j=0;
		poem=({});


/*
		while(buf=read_file(filename,1+i,1))
		{
			if(strlen(buf)>2)
			{
			buf=replace_string(buf,"\n","");
			poem+=({buf});
			j++;
			}
			i++;
		}
		length=j;

		write("22"+read_file(filename,1+i,1)+"\n"+"i="+i+"\n");

		*/

		// hmm, seems bug here.
		// lemme write a new code, dont use this dumb one.
		lines=read_file(filename);



	if(lines)
	{  
		line = explode(lines,"\n");
		for (i=0; i<sizeof(line); i++)
			if (sizeof(line[i])>2 && line[i][0..1]!="##")
			{
			poem+=({replace_string(line[i],"\n","")});
			j++;
			}
	}
	length=j;
//	write("333"+length+"---"+sizeof(explode(read_file(filename),"\n"))+"\n");
	
    poem_index=k;
    answerd=0;
    index=-1;
    chance=3*100/(1+length);
	if (length == 2)
		chance=50;
//    if(length<3)	chance=100;
    return;
}

int find_newline()
{
    index++;
//	write("index = "+index+" length="+length+" chance="+chance+"\n");
    while(index<length)
	{
		if(random(100)<chance)
			return 1;
		else
			index++;
    }
    return 0;
}
string enscript(string arg)
{    string result;
    string *color=({BLK,RED,GRN,YEL,BLU,MAG,CYN,WHT,
      HIR,HIG,HIY,HIB,HBRED,HBGRN,HBYEL,
      HBBLU,HBMAG,BBLK,BRED,BGRN});
    int len,i;
    len=sizeof(color);
    result="";
    i=sizeof(arg);
    while(i>2) {
	if(random(2)==0) {
	    result=color[random(len)]+NOR+arg[i-2..i-1]+result;
	} else {
	    result=arg[i-2..i-1]+result;
	}
	i-=2;
    }
    result=NOR+arg[0..1]+result;
    return result;
}
