
inherit QUESTNPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
	set_name("薛衣人", ({ "xue yiren", "xue" }) );
	set("nickname",RED"血衣人"NOR);
        set("title","杀人庄     大庄主");
        set("gender", "男性" );
        set("quality","evil");
        set("age", 48);
	set("int", 52);
	set("per", 15);
	set("fle",40);
	set("long",
"这老人面容清瘦，穿着件蓝布长衫，风采也没有什么特异处，只不过一双眼睛
却是炯炯有光，令人不敢逼视。他身後背着柄乌鞘长纫，背剑的方式，任何人
都想得到他如此背剑，只为了能在最短助时间里将剑拔出来。\n"
		);
        set("max_force", 3000);
        set("force", 3000);
	set("force_factor", 130);
	set("cor",60);
	set("str",40);
        set("combat_exp", 10000000);
		set("bellicosity",0);
        set("score", 7200);
        set_skill("sword", 200);
        set_skill("force", 140);
        set_skill("parry", 180);
        set_skill("literate", 50);
	set_skill("dodge", 350);
        set("agi",25);
        set("int",30);
		set("chat_chance",10);
/*		set("chat_msg",({

		})	);
  */
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword.jingtianyijian" :),
        }) );
    set_skill("huanhua-sword", 180);
        map_skill("sword", "huanhua-sword");
		
	setup();
        carry_object("/obj/weapon/sword")->wield();
}
/*
void init()
{
        object room;
        remove_call_out("hunting");
        if(!room=environment()) return 0;
	if(!room->query("no_fight"))
        call_out("hunting",1);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
                if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])||userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->kill_ob(this_object());
        }
}
*/
