// CYNGIRL.C
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(HIW"白衣"NOR"女子", ({ "white girl","girl" }) );
        set("long", "在朦胧的迷雾中，你只能模模糊糊的看到她的身影，但不知为何，你的心一下子变
得无比的宁静和祥和。\n");
	set("age",18);
        set("per",50);
        set("gender", "女性");
        set("attitude", "friendly");
        set("combat_exp", 500000);  
	set("kee", 1500);
        set("max_kee", 1500);
        set_skill("meihua-shou",80);
        set_skill("unarmed",80);
        set_skill("force",50);
        set_skill("qidaoforce",50);
        set_skill("dodge",80);
        set_skill("parry",80);
        set_skill("fall-steps",80);
        set_skill("iron-cloth",100);
        set_skill("spring-water",200);
        set("force_factor",10);
        set("max_force",100);
        set("force",200);
        map_skill("force","qidaoforce");
        map_skill("dodge","fall-steps");
        map_skill("unarmed","meihua-shou");                         
        map_skill("iron-cloth","spring-water");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action,"iron-cloth.bingwantianzhang"  :),

        }) );
        
	setup();
	carry_object(__DIR__"obj/white_cloth")->wear();
}

void init()
{
	::init();
	add_action("do_look","look");
}

void leave_room(object me)
{
	object pipe;
	
	tell_object(me,WHT"迷雾流转，人踪已缈，就在你怀疑自己是不是眼花的时候，你看到了沙滩上有一件
物事，难道，是那位女子留下的？你满腹狐疑的拾起了那个物事，发现是一只笛子。\n"NOR);
	pipe=new(__DIR__"obj/saintpipe");
	pipe->move(me);
	pipe->set("receiver",me);
	destruct(this_object());
	return ;
}

int do_look(string arg)
{
	object ob,me;
	
	if(!arg) return 0;
	me=this_player();
	ob=present(arg,environment());
	if(!ob) return 0;
	if(ob==this_object()&&(!me->query_temp("lovestory1_epilogue"))) 
	{		
		tell_object(me,"眼花了吗？怎么什么都看不到？\n");
		return 1;
	}
	return 0;
}