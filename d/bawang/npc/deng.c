inherit NPC;
#include <ansi.h>

void create()
{
        set_name("邓定候", ({ "deng dinghou", "deng"}) );
        set("nickname", HIR "神拳小诸葛"NOR);
	set("vendetta_mark","shaolin");
	set("gender", "男性" );
	set("age", 44);
	set("per", 25);
	set("attitude","friendly");
	
	set("long",
		"中原镇远镖局的主人，除了肚子微微有些发福外，别的看上去都不输\n给壮小伙们。\n"
	);
	set("chat_chance", 1);
	set("chat_msg", ({
        name()+"一字一字沉声道：实在想不到这内奸原来就是你－百－里－长－青！！\n",
        }) );
	
	set("combat_exp", 4000000);
        set("no_busy",5);
        
	set_skill("move", 200);
	set_skill("dodge", 200);
	set_skill("force", 160);
	set_skill("unarmed",200);
	set_skill("dragonstrike",200);
	set_skill("parry",200);
	set_skill("fengyu-piaoxiang",200);
	
	map_skill("dodge", "fengyu-piaoxiang");
	map_skill("unarmed", "dragonstrike");
	map_skill("move","fengyu-piaoxiang");
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object(__DIR__"obj/flag");
}
