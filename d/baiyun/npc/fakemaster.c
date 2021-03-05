// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("叶万仞", ({ "ye wanren", "ye" }) );
        set("nickname", RED"一片孤城万仞山"NOR);
        set("long",
"他的脸枯瘦丑陋，一双眼睛深深的下陷，虽然也目光似电，但着实有几分
阴狠辛辣之意。\n"
	);
        create_family("白云城",2, "副城主");
		set("rank_nogen",1);
    	set("ranks",({"琴使","棋使","书使","画使","剑士",CYN"剑使"NOR,CYN"剑师"NOR,HIC"大剑师"NOR}));
        set("combat_exp", 2000000);
        set("score", 200000);
    	set("reward_npc", 1);
		set("difficulty", 5);
        set("gender", "男性" );
        set("class","baiyun");
        set("age", 44);
	    set("per", 40);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
        }) );
		set("attitude","friendly");
        set("max_force", 8000);
        set("force", 8000);
        set("max_kee",8000);
        set("max_gin",8000);
        set("max_sen",8000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "叶孤城凝望海天之处，轻捋长髯微微一笑道：紫禁之颠，一剑西来。\n",
        }) );

        
        set_skill("move", 150);
		set_skill("daode",150);
        set_skill("parry", 120);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 130);
		set_skill("sword", 140);
		set_skill("unarmed",120);
		set_skill("changquan",120);
		set_skill("feixian-steps",140);
		set_skill("feixian-sword",140);
		set_skill("chessism",60);
		
        map_skill("dodge", "feixian-steps");
		map_skill("sword", "feixian-sword");
		map_skill("parry", "feixian-sword");
		map_skill("unarmed", "changquan");
		map_skill("force","chessism");

        setup();
        carry_object(__DIR__"obj/yemask")->wear();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/xiaolian")->wield();

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
		 	add_action("do_enjoy","join");

}


int do_enjoy()
{
	object me = this_player();
	if (REWARD_D->riddle_check(this_player(),"王图一梦") !=8 
		&& REWARD_D->riddle_check(this_player(),"王图一梦") !=9 )
		return 0;
	ccommand("emote 轻捋长髯，肃然道：且与剑狂比试，看尔修为究竟如何。");
	REWARD_D->riddle_set(me,"王图一梦",9);
	return 1;
}

void greeting(object ob)
{
        object corpse;
        if( !ob || environment(ob) != environment() ) return;
		if (REWARD_D->riddle_check(ob,"王图一梦") !=7 
			&& REWARD_D->riddle_check(ob,"王图一梦") !=8)
			return;
		tell_object( ob, CYN"
叶孤城哼了一声说：我知你来意。古来为大事者不拘小节，行远谋者不图
小利，死个把来人又算得了什么？时值乱世，入(join)我白云城，立千秋
功业，方为上上之选。\n\n"NOR);
		REWARD_D->riddle_set(ob,"王图一梦",8);
		return;
}


void re_rank(object student)
{
	int exp;
	exp = student->query("combat_exp");
	if( exp <= 1200000 )
	{
			::re_rank(student);
			return ;
	}
	student->set_temp("annie/by_fight_ss",1);
	return;
}



/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
