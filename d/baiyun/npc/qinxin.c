// XXDER@FY3
inherit NPC;
#include <ansi.h>

int leave();

void create()
{
    set_name("琴心" , ({ "qin xin","qin" }) );
    set("nickname",HIC"枕琴囊"NOR);
    set("long", "
一个白衣女子席地而坐，膝上放着一张焦尾琴，正自弹奏。身周树木上停满了
鸟儿，和琴声或一问一答，或齐声和唱。\n");
	set("attitude", "friendly");
    set("age", 22);
    set("per",40);
    set("class","huashan");
    set("gender", "女性" );      
    create_family("白云城",1, "才女");
    set("combat_exp", 2500000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "琴心轻拂膝上瑶琴，琴音和鸟语互相应答，间间关关，宛转啼鸣。\n",
        "琴心柳眉微蹙，琴声忽高忽低，忽轻忽响，“铮”的一声，一根「徵弦」忽然断了。\n",
	}) );
         set("inquiry",  ([
				"救治剑胆" :  (: leave :),
        ]) );

set_skill("music", 150);
   	set_skill("magic", 150);
   	
   	set_skill("dodge", 200);
    set_skill("anxiang-steps", 200);
    set_skill("qingfeng-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("spring-water", 100);
    map_skill("iron-cloth","spring-water");
    map_skill("sword","qingfeng-sword");
    map_skill("dodge","anxiang-steps");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.yexuechiji" :),
        }) );

	setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object(__DIR__"obj/lvqi");
    carry_object("/obj/weapon/sword")->wield();
}

void attempt_apprentice(object ob)
{
    command("say  小女子只授艺，不收徒。");
	return;
    	
}

void init()
{       
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
}


void greeting(object ob)
{
        object qin;
        if( !ob || environment(ob) != environment() ) return;
		
		qin = this_object();
		
		if (ob->query("free_learn/music") && !ob->query("annie/music_choose"))
		{			
			message_vision(CYN"琴心向$N盈盈拜下，双手轻拂，琴声幽远惆怅，正是一曲，忆故人。\n"NOR,ob);
			tell_object(ob,CYN"细细的语声传来：小女子无以为些，愿以琴艺相授。\n"NOR);
		}
		return ;
}

int leave()
{
	object room = load_object("/d/baiyun/dragonplace");
	int i = REWARD_D->riddle_check(this_player(),"王图一梦");
	if (is_fighting())
	{
		tell_object(this_player(),name()+"正忙，顾不上与你搭话。\n");
		return 1;
	}
	
	if ( i !=4 && i != 5 && i != 6)
		return 0;
	if (environment() == room)
		return 0;
	delete("chat_msg");
	message_vision(WHT"$N眉头一皱，幽幽叹了口气道：叶师兄，你终于对我们开始下手了么？\n$N随手一拂，焦尾琴七弦俱断，唤鹤而去。\n"NOR, this_object());
	move(room);
	return 1;
}


int do_answer(string arg) // 去死吧!!!! ><"
{
	object me;
	int a;
	me = this_player();
	
	if (!arg || sscanf(arg, "%d", a)!=1)
		return notify_fail("你要选择什么？\n");
	if (a<1 || a>5)
		return notify_fail("你要选择什么？\n");

	if (a== 5)
	{
		message_vision(CYN"琴心脸色慢慢转为苍白，喃喃道：果然被你料中，果然．．．\n"NOR,me,this_object());
		message_vision(CYN"琴心轻轻颤抖，望向$N身后的远方：云星，云星，你若有闻，请为我奏一曲末世广陵．．．\n"NOR,me,this_object());
		message_vision(HIR"\n琴心忽自焦尾琴下抽出一把匕首,抬手处插入自己胸口，鲜血飞溅而出，染红了五丈方圆。\n"NOR,me,this_object());
		message_vision(WHT"\n一阵幽遥的琴声远远自白云城中传来，在风中慢慢飘散。\n"NOR,me,this_object());
//		me->set("annie/music_choose",-1);	// you can choose again
		delete_temp("last_damage_from");
		die();
		return 1;
	}

	me->set("annie/music_choose",a);
	message_vision(CYN"琴心默然半晌，轻轻点了点头。\n"NOR,me,this_object());
	return 1;
}

int recognize_apprentice(object ob)
{
	
	if (!ob->query("free_learn/music"))
	{
		if (ob->query("free_learn/by_magic"))
			return 1;
		ccommand("bored "+ob->id(1));
		return 0;
	}
		
	if (!ob->query("annie/music_choose"))
	{
		message_vision(CYN"\n琴心微一揉弦，长长地叹了口气，点了点头：你有恩於琴心，琴心自当相报。\n"NOR,ob,this_object());
		message_vision(CYN"琴心抬起脸，清澈有若一洗长空的双眸凝定在$N身上：你望琴心以何物回报？\n"NOR,ob,this_object());
		message_vision(HIW"　　1"HIY"十面埋伏曲 "HIW"2"HIY"潇湘水云曲 "HIW"3"HIY"碧海潮生曲 "HIW"4"HIY"清心普善曲 "
		HIW"5"HIY"以身相许罢 \n选择一项：answer 1-5\n"NOR,ob,this_object());
		add_action("do_answer","answer");
		ob->set_temp("annie/choose_music",1);
		return 1;
	}

    return 1;
}



int prevent_learn(object me, string skill)
{
  	if (skill == "magic" && me->query("free_learn/by_magic"))
  		return 0;
  	
  	if (skill == "music" && me->query("free_learn/music"))
  		return 0;
  
   	command("emote 轻轻拂动琴弦，眼中盈盈水光。");
   	command("flook");
   	return 1;
   	
}


int prevent_shown(object me, string skill)
{
	
	if (skill == "magic" && me->query("free_learn/by_magic"))
		return 0;
		
	if (me->query("annie/music_choose") == -1)
		return 1;

	if (me->query("free_learn/music") && (skill == "music"))
		return 0;
	
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
