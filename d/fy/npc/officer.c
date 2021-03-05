#include <ansi.h>
inherit NPC;

string *first_name = ({ 
"上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫","尉迟","公羊","澹台","公治",
"宗政","濮阳","淳于","单于","太叔","申屠","公孙","仲孙","辕轩","令狐","钟离","宇文",
"长孙","幕容","司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷","公良",
"拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦","段千","百里","东郭","南郭",
"呼延","归海","羊舌","微生","梁丘","左丘","东门","西门",	});
string *name_words = ({ "藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付","皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄","米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍","虞","万","支","柯","昝","管","卢","英","万","候", });

string send_mail();
string receive_mail();
string quest();
object find_env(object ob);

void create()
{
    	set_name("王风", ({ "officer wang", "officer","wang" }) );
		set("title", "风云驿驿长");
		set("gender", "男性" );
		set("NO_KILL",1);
		set("no_arrest",1);
		set("age", 43);
		set("long",	"王风担任风云驿的驿长已经有几年了，人很好，深得风云城
居民喜爱，即使没有信件，大家也常会来驿站跟他聊天。\n");
		set("combat_exp", 800);
		set("attitude", "friendly");
		set("inquiry", ([
		"找找" : (: quest() :),
		"find" : (: quest() :),
		"job" : (: quest() :),	
		"失物" : (: quest() :),
		"驿站" : "是啊... 这里就是风云驿，你要寄信或租马车吗？",
		"寄信" : (: send_mail :),
		"信" : (: send_mail :),
		"收信" : (: receive_mail :),
		"mail" : (: receive_mail :),
	]) );
	set_skill("literate", 70);
	set_skill("unarmed", 400);
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	add_action("do_rent","rent");
}

string send_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？用信箱就可以寄信了。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "哦... 要寄信是吗？这是你的信箱，寄信的方法信箱上有说明。\n";
}

string receive_mail()
{
	object mbox;

	if( this_player()->query_temp("mbox_ob") )
		return "你的信箱还在吧？你所有的信都在里面。\n";
	if( !environment()
	||	base_name(environment()) != query("startroom") )
		return "真是抱歉，请您等一下到驿站来找我吧。\n";
	seteuid(getuid());
	mbox = new(MAILBOX_OB);
	mbox->move(this_player());
	return "好，待我找找....有了，你的信箱在这，慢慢看吧，不打搅你了。\n";
}

int do_rent(string arg)
{

	object ob, chefu;
	object me = this_player();
//	object silver;
	if (arg != "carriage" && arg != "mache")
	{
		return notify_fail("你要租什么？\n");
	}

	if (query("mark/rented"))
	{
		tell_object(me,"
王凤说：哎呀，马车已经租出去了，这位客官是不是过会儿再来？
如果等不及，我给你指点一条捷径吧。输入Help newbie，而后选择
路径指南，那里有几大城镇的往返路径说明。\n");
		return 1;
	}
	if (me->query_temp("marks/wangfeng")) 
		me->delete_temp("marks/wangfeng");
	else {
	    if (me->query("deposit")<800)
	    	return notify_fail("你银行里的存款不足八两银子。\n");
		me->add("deposit",-800);
		tell_object(me, "风云驿站从你的账户上转走了八两银子。\n");
	}
	
	ob=new(__DIR__"obj/carriage");
    ob->move(environment());
	message_vision("$N驶了过来 \n",ob);

	chefu=new(__DIR__"chefu");
	chefu->move(environment());
	chefu->get_quest("/d/fy/carriageway");
	chefu->set_carriage(ob);
	message_vision("$N走了过来 \n",chefu);

	set("mark/rented",1);
	message_vision("$N打开马车门，坐进了马车 \n",me);
	me->move(ob);
	chefu->go_now();
	
	call_out("check_status",30,chefu);
	return 1;
}

int check_status(object ob)
{
	if (!ob)
	{
		set("mark/rented",0);
	}else
	{
		call_out("check_status",30,ob);
	}
}

object generate_it(int exp,string name)
{
	object mail,room,*ulist/*, place*/, ob;
	int i,m,flag,fdd,num;
	string file, where;
	ulist=objects();
	m=sizeof(ulist);
	flag=1;

	mail=new("/obj/specials/annie/mail");
	mail->invoke(name);

	while (flag)
	{
		i=random(m);

//		write ("attemp ------fdd = " + fdd + "\n");
//		write (sprintf("it is %O\n",ulist[i]));
		
		if (!ulist[i])
			continue;
		if (!environment(ulist[i]) && !ulist[i]->query("short"))	// not a room: something in the planar void
			continue;
		if (sscanf(file_name(ulist[i]),"/adm/%s",file) == 1)	// daemons
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/user#%d",num) == 1)// players
			continue;
		if (sscanf(file_name(ulist[i]),"/obj/login#%d",num) == 1)// players
			continue;
		if (!ulist[i]->query("name"))	// 天知道是什么东西
			continue;
		
		if (!ulist[i]->query("short") && fdd < 3)		// 尽量放在屋子里，这样减少exp的循环, and teach ppl hiding places.
		{
			fdd++;
			continue;
		}

		room=ulist[i];
		
		// 不能在 player身上也不能在 player携带的容器里		
		if (userp(room))	continue;		
		if (objectp(environment(room)) && userp(environment(room)))	
			continue;						
		
		// 这个东西最终应该存在在某一个房间里面，去除那些无环境的NPC					
		ob = find_env(room);				
		if (!ob)	continue;
			
		if (ob->query("no_fight"))			continue;
		if (ob->query("no_death_penalty"))	continue;
		if (ob->query("no_fly"))			continue;	
		if (ob->query("perma_exist"))		continue;
		if (ob->query("no_lu_letter")) 		continue;	// Some rooms are tricky, can't get
					
		where = file_name(ob);
    	if (   where[0..7]=="/d/death"
    		|| where[0..4]=="/d/fy"			// including fy,fycycle,fywall
    		|| where[0..7]=="/d/eren2"
			|| where[0..6]=="/d/maze"
			|| where[0..5]=="/d/wiz"
			|| where[0..9]=="/d/welcome"
			|| where[0..9]=="/d/phoenix"
			|| where[0..8]=="/d/bashan"
			|| where[0..8]=="/d/zhaoze"
			|| where[0..9]=="/d/taoyuan"
			|| where[0..9]=="/d/shanliu"
			|| where[0..2]=="/p/"
			|| where[0..4]=="/obj"
			)
			continue;
								
		// 当这个地方是一个NPC时
		if (room->query("combat_exp"))
		{
			if (room->query("NO_KILL"))					continue;
			if (room->query("vendetta_mark/authority"))	continue;
			if (room->query("possessed"))				continue;
			if (room->query("no_lu_letter"))			continue;
			if (room->query("combat_exp")> 10050000)	continue;	// capped around 10M				
			if (room->query("combat_exp") > exp/10*12 && fdd < 20)
			{
				fdd++;
				continue;
			}

			if (room->query("combat_exp") < exp/10*8 && fdd < 10)
			{
				fdd++;
				continue;
			}
		}
	
		if (room->query("id") == "skeleton" || room->query("id") == "corpse")
			continue;
			
		if (mail->move(room))
		{
//			CHANNEL_D->do_sys_channel("sys","move to " + file_name(room) + "\n");
//			write("move to "+ file_name(room)+"\n");	
			flag=0;
		}
	}
	return mail;

}

object find_env(object ob)
{
	while(ob)
	{
		if(ob->query("coor")) return ob;
		else 
			ob=environment(ob);	
	}
	return ob;
}

string quest()
{
	string arg, name;
	int /*i,n,m,*/ size, reward, exp;
	object room, silver,room2;
	
	object me = this_player();
	
	if (me->query("quest/short") == "到风云驿站寻找失物")
	{

		name = first_name[random(sizeof(first_name))];
		name += name_words[random(sizeof(name_words))];
		if( random(10) > 2 ) name += name_words[random(sizeof(name_words))];

//		write(sprintf("me is %O\n",me));
		me->set("annie_questx/mail",generate_it(me->query("combat_exp"),name));
		me->set("annie_questx/index", name);
		me->set("quest/short", WHT"寻找送给"+name+WHT"的信"NOR);
		me->set("quest/location", "未知");
		me->set("quest/duration",900);	
		me->set("quest_time",time());
		arg="action王风一脸赫色：俺、俺把给"+name+"的信弄丢了，快帮俺寻一寻(locate quest)。\n";
		tell_team(me,HIY+me->name()+HIY"的任务改变了！\n"NOR);
		return arg;

	}
	else
		return "action王风吹胡子瞪眼道：俺风云驿站信用良好从不丢信！";
	
	return " ";
}

int accept_object(object me,object ob)
{
	if (ob->query("desc_ext") != "任务物件")
		return 0;
	
	if (ob->query("marks") != me->query("annie_questx/index"))
		return 0;
	
	if (ob!= me->query("annie_questx/mail"))
		return 0;
	
	me->delete("annie_questx");

	if ( QUESTS_D->verify_quest(me,"寻找失物" ))
		QUESTS_D->special_reward(me,"寻找失物");
	
	return 1;
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/



