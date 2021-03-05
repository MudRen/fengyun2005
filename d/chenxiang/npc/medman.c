#include <ansi.h>
inherit SMART_NPC;

int init_quest();

void create()
{
	set_name("中药店老板", ({ "medman" }) );
	set("gender", "男性" );
	set("age", 75);
	set("long","一个正忙得不可开交的中药店老板，他正在煮汤。\n");
	set("combat_exp", 5000000);
	set("attitude", "friendly");
	set("per",1);
    set("inquiry", ([
        "当归补血鱼汤" : "那你可要买：北芪，淮山，党参，杞子，和当归．\n",
		"soup" : "那你可要买：北芪，淮山，党参，杞子，和当归．\n",
        "麻沸散":	(: init_quest :),
        "头发":		"这个只有你自己想办法了。\n",
        "蜡丸":		"据说有这个东西的人，眼睛比蜡丸还大还圆，不过，你要去找他，
最好先去找玉脖套，否则小命难保啊。\n",
        "蛇珠":		"我夜观天象，三日前有异蛇降于此地，你可四处查看。\n",
        "玉脖套":	"你说这玉的东西该找谁呢？\n",
        "戴寅":		"戴寅是我的远房侄子。\n",
        "恩人":		"在下救人无数，想来也算得上你的恩人。\n",
        "大恩人":	"在下救人无数，想来也算得上你的恩人。\n",
     ]));

	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
        
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","taiji",1);
	setup();
	carry_object("/obj/armor/cloth",([	"name": "白褂",
    						"long": "一件白大褂。\n",
    						 ]))->wear();    
}

void init(){
	
	::init();
	add_action("do_answer","answer");
}


string *material_names=({ "蛇珠","头发","蜡丸" });

int accept_object(object me, object ob)
{
	string ob_name;
	int i,success,makeup_ok;
	object drug;
		
	if(ob->query("marks") == "special_coin")
 	{
  		message_vision("$N看了$n一眼，指了一下小火炉。\n",this_object(),me);
  		message_vision("$N犹豫了一下，将身上的一文钱扔入小火炉中。\n",me);
  		message_vision("铜钱上的裂痕中冒出一股绿烟，将整个铜钱染成碧绿！\n",me);
  		ob->set("marks","special_green_coin");
  		ob->set("long","这是一枚碧绿的铜钱，铜钱上有一条浅浅的裂痕。\n");
  		return 0;
 	}
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")!=9
		&& REWARD_D->riddle_check(me,"魂断鹊桥")!=10)
		return 0;	
			
	ob_name=ob->query("name");
	success=1;
	makeup_ok=0;
	for(i=0;i<3;i++)
	{
		if(ob_name==material_names[i])
		{
			if(me->query_temp("medman/"+ob_name))
			{
				command("say 这原料你已经给过我了！”\n");
				return 0;
			}
			me->set_temp("medman/"+ob_name,1);
			command("say 好，此物我且收下。");
			makeup_ok=1;
		}
		success=success*me->query_temp("medman/"+material_names[i]);
	}
	if(!success) return makeup_ok; 
	
	tell_object(me,CYN"中药店老板满意地说：原料都齐了，稍候片刻。
	
中药店老板转入后堂。

片刻，中药店老板走过来把一包东西悄悄地塞给你说，“大功告成！”\n"NOR);

	message_vision(YEL"\n$n对$N邪恶的笑着，一副不怀好意的样子。\n",me,this_object());
	me->delete_temp("medman");
	drug = new(__DIR__"obj/yj_drug");
	if(!drug->move(me))
		drug->move(environment(me));
	REWARD_D->riddle_set(me,"魂断鹊桥", 10);
	
	if (REWARD_D->riddle_check(me,"局中局")==1)
		tell_object(me,WHT"\n（这环环相套，竟然又回到了原地，既然如此，还是随机应变，设法"YEL"警告"WHT"袁姬才好）\n"NOR);
		
	return 1;
}


int	do_answer(string arg){
	
	object me=this_player();
	
	if (!me->query_temp("marks/ask_medman"))	return 0;
	
	if (arg != "dai yin" && arg != "戴寅" )	
	{
		command("shake");
		return 1;
	}
	
	me->delete_temp("marks/ask_medman");
	
	message_vision(YEL"$N忽然露出恍然大悟的神情。\n"NOR, this_object());
	tell_object(me,CYN"
中药店老板满脸堆笑地说：对对，麻沸散，戴寅的麻沸散，哦，不不，我的麻沸散。
没想到丐帮的大侠们也要麻沸散。\n"NOR);

	message_vision(YEL"\n$n对$N邪恶的笑着，一副不怀好意的样子。\n",me,this_object());
	
tell_object(me,CYN"
中药店老板说：只是此药配制不易，需要"WHT"蛇珠"CYN"磨成的粉，"WHT"蜡丸"CYN"的壳，以及刚死去
女子的一根"WHT"头发"CYN"。你把这些都找齐了给我，再问我配"YEL"麻沸散"CYN"就行了。\n"NOR);

	REWARD_D->riddle_set(me,"魂断鹊桥",9);
	return 1;
}

			
	

int	init_quest(){
	object me= this_player();
	
	if(REWARD_D->riddle_check(me,"魂断鹊桥")!=8
		&& REWARD_D->riddle_check(me,"魂断鹊桥")!=9
		&& REWARD_D->riddle_check(me,"魂断鹊桥")!=10)		return 0;
		
	if(!me->query_temp("marks/ask_medman")){
		command("?");
		command("say 麻沸散，你要此物。。。。是谁叫你来的？");
		me->set_temp("marks/ask_medman",1);
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")==9
		|| REWARD_D->riddle_check(me,"魂断鹊桥")==10)
	{
		command("say 照我说的把东西拿来就行了。");
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"魂断鹊桥")==8)
	{
		command("say 麻沸散，你要此物。。。。是谁叫你来的？");
		me->set_temp("marks/ask_medman",1);
		return 1;
	}
	
	return 0;
}
	
	
		
	