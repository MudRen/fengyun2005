#include <ansi.h>
inherit NPC;

void create()
{
        set_name("土匪老大", ({ "bandit chief", "chief" }) );
        set("gender", "男性");
        set("age", 39);
        set("long",
                "这家伙眼神凶恶，一双精光四射的眼珠正盯著你的脖子。\n");
        set("combat_exp", 650000);
        set("attitude", "aggressive");
        set("chat_chance", 10);
        set("chat_msg_combat", ({
                "\n土匪老大阴恻恻地说道：乖乖地躺下吧！\n",
                "\n土匪老大虎吼一声，欺身上前。\n"
        }) );
        
        set_skill("blade", 150);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("shenji-blade",90);
        set_skill("shenji-steps",100);
        set_skill("unarmed",150);
        set_skill("yiyangzhi",80);
        
        map_skill("unarmed","yiyangzhi");
        map_skill("blade","shenji-blade");
        map_skill("parry","shenji-blade");
        map_skill("dodge","shenji-steps");
        

        setup();
        carry_object("obj/weapon/blade")->wield();
        carry_object(__DIR__"obj/leather")->wear();
}

void start_help()
{
        message_vision(CYN"一条人影从树林间跃出，身手矫健，显是武功不弱。\n"NOR,this_object());
        command("say 哈哈哈... 连这几个小角色也打发不了，站开一点！\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object ob;
	message("vision",name() + "笑道：好好守着，大爷我去睡觉了！\n", environment(),this_object() );
	command("escape");
	if (ob=present("bandit",environment()))
		ob->set("called_help",0);
	destruct(this_object());
}
