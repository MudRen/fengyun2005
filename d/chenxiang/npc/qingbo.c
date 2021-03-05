// (C)1998-2000 Tie Yu

#include <ansi.h>

inherit NPC;
int tell_him();
int ass_come();
int ass_in(object me);

void create()
{
	set_name("清波公子", ({ "prince qingbo","qingbo" }) );
	set("gender", "男性" );
	set("long","本是富贵人家，但因为犯上作乱，已经满门抄斩，唯独清波公子得以幸免。\n");
	set("age", 25);
	set("combat_exp", 2500);
	set("attitude", "friendly");
	set("per",30);
    
    set("chat_chance", 1);
    set("chat_msg", ({
         "清波公子喃喃道：袁姬．．．袁姬．．我知道你来了．．．。\n",
    }) );
    
    set("inquiry", ([
         "袁姬" : (: tell_him :),
         "yuanji" : (: tell_him:),
         "baohu": 	(: ass_come :),
         "保护":		(: ass_come :),
         "恩人":		"如果你能让我和袁姬团聚，你就是我们的大恩人。\n",
         "大恩人":	"如果你能让我和袁姬团聚，你就是我们的大恩人。\n",
        ]));
	set("qingbo", 1);
	setup();
	carry_object(__DIR__"obj/scloth2")->wear();
}

int tell_him()
{
 	object me;
 	me =this_player();
 	tell_object(me,"清波公子道：袁姬本是和我青梅竹马，但因为我家被满门抄斩，\n");
 	tell_object(me,"她已经被内宫的米公公选中，很快就要送入后宫了！\n");
 	tell_object(me,"清波公子颓丧道：除非袁姬死了，我们恐怕再也见不到了！\n");
 	return 1;
}

void init(){
	
//	object me;
	
	::init();
}


int ass_come(){
	
	object me = this_player();
	object ass1;
	
	if (ass1= present("assassin"))
	{	
		command("point"); 
		command("shiver");
		return 1;
	}
	
	command("say 唉，我有什么可保护的，没了袁姬，我活着还有什么意思。");
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥") == 2) {
		if (REWARD_D->riddle_check(me,"局中局")==1)
			tell_object(me,WHT"\n你暗自琢磨，恩，该有刺客从湖里跳上来了吧！\n"NOR);	
		if (!query_temp("ass_in_work"))
		{
			call_out("ass_in", 10+random(10), me);
			set_temp("ass_in_work",1);
			
		}
	}
	return 1;
}	
	

int	ass_in (object me)	{
	
	object ass;
	
	if (!me || environment(me) != environment())	
	{
		delete_temp("ass_in_work");
		delete_temp("marks/protector");
		return 1;
	}
	
	set_temp("ass_in_work",1);
	set_temp("marks/protector",me);
	
	message_vision(BLU"湖水忽然一阵荡漾，嗖嗖地跳出个黑影，剑气森森，直扑清波公子。\n"NOR,me);
	ass = new(__DIR__"assassin");
	if (ass)	ass->move(environment());
	
	return 1;	
}		

void die(){
	
	object prot, ass1/*, ass2*/;
	command("say 袁姬、袁姬，我先走一步了！");
	
	ass1 = present("assassin");
	
	prot = query_temp("marks/protector");
	
	if (objectp(prot))
	{
		if (environment(prot) == environment())
		if ( (ass1 && prot->is_fighting(ass1)))
		{
			if (REWARD_D->riddle_check( prot, "魂断鹊桥")==2)
				REWARD_D->riddle_set(prot,"魂断鹊桥", 4);
		
		}
	}
	
	::die();
}

		
		