inherit NPC;
inherit F_MASTER;
#include <ansi.h>

int leave();
int back();

void create()
{
        set_name("叶孤城", ({ "master ye", "master" }) );
        set("nickname", HIC"一剑西来"NOR+HIR" 天外飞仙"NOR);
        set("long","
一个白面微须，穿著身雪白长袍的人。他的脸很白，既不是苍白，也不是惨白，
而是一种白玉般晶莹泽润的颜色。他的眼睛并不是漆黑的，但却亮得可怕，就
像是两颗寒星。他漆黑的头发上，戴著顶檀香木座的珠冠，身上的衣服也洁白
如雪，仿佛是天上的仙人一般。
\n"
	);
        set("gender", "男性" );
        set("class","baiyun");
        set("age", 44);
        set("str", 100);
       	set("per", 20);
	    set("combat_exp", 15000000);

		set("no_heal",1);
		set("max_kee",10000000);
		set("max_gin",100000);
		set("max_sen",100000);
		set("eff_kee",100000);
		set("kee",100000);
        
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
        }) );
	
		set("attitude","friendly");
                
        set("chat_chance", 0);
        set("chat_msg", ({
			(: back() :),
        }) );

        create_family("白云城",1, "城主");
		set("rank_nogen",1);
    	set("ranks",({"琴使","棋使","书使","画使","剑士",
                      CYN"剑使"NOR,CYN"剑师"NOR,HIC"大剑师"NOR}));

        set("score", 200000);
    	set("reward_npc", 1);
	set("difficulty", 40);
        
        set("inquiry",  ([
                "leave": (: leave :),
        ]) );
     
        set_skill("move", 180);
	set_skill("daode",200);
        set_skill("parry", 170);
        set_skill("dodge", 170);
        set_skill("force", 180);
        set_skill("literate", 150);
	set_skill("sword", 220);
	set_skill("unarmed",150);
    set_skill("music",130);
	
	set_skill("feixian-steps",200);
	set_skill("feixian-sword",200);
	set_skill("calligraphy",160);
	set_skill("chessism",160);
	set_skill("magic",150);
	set_skill("painting",200);
	
	map_skill("magic","music");
	map_skill("dodge", "feixian-steps");
	map_skill("sword", "feixian-sword");
	map_skill("force", "chessism");
	map_skill("parry", "feixian-sword");
	map_skill("unarmed", "calligraphy");
	map_skill("move","feixian-steps");

        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/bsword")->wield();
	carry_object(__DIR__"obj/bcloth")->wear();
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

/*
int recognize_apprentice(object ob)
{
	if (!ob->query("free_learn/magic"))
	{
		ccommand("heihei "+ob->id(1));
		return 0;
	}


    return 1;
}



int prevent_learn(object me, string skill)
{
  	if (skill != "magic")
  	{
      		command("haha");
      		return 1;
  	}
  	return 0;
}


int prevent_shown(object me, string skill)
{
	if (me->query("free_learn/magic") && (skill == "magic"))
		return 0;
	
	return 1;
}*/

void greeting(object ob)
{
        object corpse;
		object me = ob;
		object box;
		mapping data;
		
        if( !ob || environment(ob) != environment() ) return;
		if (REWARD_D->riddle_check(ob,"王图一梦") ==14)
		{
			message_vision(YEL"叶孤城颤声道：愚设计十年，杀人无算，就为这一棋局，结果怎么．．怎么会这样．．\n"NOR,me);
			message_vision(YEL"叶孤城脸如死灰："CYN"斩蟒台"YEL"上那人明明向我保证万无一失，怎会这样！！！\n\n"NOR,me);
			message_vision(MAG"十年梦幻，终成泡影，叶孤城竟然站立不稳，一交跌倒在地上。\n\n"NOR,me);
			ob->set("free_learn/music",1);
			REWARD_D->riddle_done(ob,"王图一梦",100,1);
			
			data = ([
				"name":		"王图一梦",
				"target":	ob,
				"att_1":	"con",
				"att_1c":	1,
				"mark":		1,
			]);
		
			REWARD_D->imbue_att(data);
					
			start_busy(20);	// grin...
			return;
		}

		if (REWARD_D->riddle_check(ob,"王图一梦") !=10 && REWARD_D->riddle_check(ob,"王图一梦") !=11 )
			return;
		if (REWARD_D->riddle_check(ob,"王图一梦") ==11 && ob->query_temp("annie_by_1_2_5"))
			return;
		ob->set_temp("annie_by_1_2_5",1);
    	message_vision(HIC"叶孤城凝望远方，似想起了世上最美妙的事，淡淡道： \n\n          紫禁之巅，一剑西来。\n\n"NOR,me);
    	message_vision(HIC"叶孤城嘿声道：西门吹雪。。。西门吹雪。。嘿嘿，好，好。\n"NOR,me);
    	message_vision(HIW"叶孤城自桌上拿起一只紫檀木盒，轻轻打开盒盖。\n\n"NOR,me);
    	message_vision(HIW"叶孤城双手托付给你，一字字道：你且将盒中二十六封请柬送达诸豪，务请其于\n九月十五，紫禁之巅观叶某与西门之战。嘿嘿，九月十五，斩龙之日。岂能\n不让天下英雄来观礼？\n\n"NOR,me);
    	command("emote 将盒子交给"+me->name(1)+"。");
    	message_vision(HIR"叶孤城脸色一凛道：速去速回，七日之内务必送回。\n\n"NOR,me);
		box=new(__DIR__"obj/box");
		box->move(me);
		REWARD_D->riddle_set(ob,"王图一梦",11);
		return;
}


int back()
{
	object room = load_object("/d/baiyun/baiyunguan");
	move(room);
    set("chat_chance", 0);
	return 1;
}

int accept_object(object me, object obj)
{
	if (!obj->query("annie/real_by_box") && !obj->query("thief_obj"))
	{
        message_vision(HIY"叶孤城接了过来，剑眉一挑，哼了一声，长袖一拂将"+obj->name()+"抛了出去。\n"NOR,me);
		return 1;
	}

	else if (REWARD_D->riddle_check(this_player(),"王图一梦") ==11)
	{
		if (obj->query("letters") && sizeof(obj->query("letters")))
		{
            message_vision(HIR"叶孤城脸色一沉，怒道：交代汝之事尚未完成，汝竟有脸回来见我？ \n"NOR,me);
			return 0;
		}
         message_vision(HIR"叶孤城微捻长髯，长笑道：不错，他日得登大宝，汝当也有一份功劳。 \n\n"NOR,me);
         message_vision(CYN"叶孤城拍拍$N的肩膀，笑道：如今我们只需静待时机，你且去到处走走，调适调适精神。\n\n"NOR,me);
//      message_vision(CYN"叶孤城笑道：或是你有兴致多学几分本事，孤家也可传你。\n\n"NOR,me);
		REWARD_D->riddle_set(me,"王图一梦",12);
//		me->set("free_learn/magic",1);
		return 1;
	}
	message_vision("叶孤城接了过来，看也不看，就将"+obj->name()+"自窗口抛了出去。\n",me);
	return 1;
}



void inv(object *enemy,object room)
{
	int i;
	move(room);
   	message_vision(HIC"\n暗黑的甬道突然一道流星山过，光至，剑已至。\n叶孤城脸色变了变，冷笑道：阻我大业者，死。\n" NOR, this_object());   
    set("chat_chance", 100);
	i = sizeof(enemy);
	while(i--)
	{
		if( enemy[i] && living(enemy[i]) && environment(enemy[i]) == room)
		{
			kill_ob(enemy[i]);
			enemy[i]->kill_ob(this_object());
		}
	}

}

void die()
{
	object who, owner;
	
	if(objectp(who = query_temp("last_damage_from")))
    {
    	if ( objectp(owner = killer->query("possessed")))
    		who = owner;		
		if (query("chat_chance") == 100 
			&& REWARD_D->riddle_check(who, "王图一梦") == 13)
		{
			message_vision(CYN"
叶孤城呕出口血，脸色比胜雪的长袍还要苍白，惨然一笑道： 
“王图霸业，难道真是黄梁一梦？我不甘啊！” "WHT"

叶孤城怒喝一声，剑芒大盛，长剑脱手而出，离弦之般刺向$N来。。。 

即使是再灿烂的流星，再辉煌的雷电，也及不得这天外般的一剑！ "HIR"


$N竭尽全力躲闪，长剑终还贯腹而过。\n\n"NOR,who);
			who->set("kee",1);
			COMBAT_D->report_status(who);
			who->unconcious();
			who->move(load_object("/d/baiyun/nujiao"));
		}
	}
	::die();
	return;

}

void invocation(object who,object room)
{
	object owner,*enemy,*t;
	int i;
	enemy = who->query_enemy();
	t = ({ });
	for (i=0;i<sizeof(enemy) ;i++)
		t += ({ enemy[i] });
	call_out("inv",16,t,room);
}




/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
