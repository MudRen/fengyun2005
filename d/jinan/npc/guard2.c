// guard.c

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("天牢守卫", ({ "prison guard", "guard" }) );
        set("long",
                "一个如狼似虎的天牢守卫。\n");

        set("attitude", "heroism");

        set("str", 100);
        set("cor", 26);
        set("cps", 25);

        set("combat_exp", 2000000+random(2000000));

        set_skill("unarmed", 200+random(200));
        set_skill("staff", 200+random(300));
        set_skill("parry", 200+random(300));
        set_skill("dodge", 70+random(500));
        set_skill("move", 100+random(500));

        set_temp("apply/attack", 100);
        set_temp("apply/dodge", 100);
	set_temp("apply/parry", 100);
        set_temp("apply/damage", 100+random(300));
        set_temp("apply/armor", 70);
        set_temp("apply/move", 100);
        set("chat_chance", 1);
        set("chat_msg", ({
"天牢守卫沉声道：天牢重地，闲人莫入！\n"
}) );

		set("prison_guard",2);

        setup();

        carry_object(__DIR__"obj/yafu")->wear();
        carry_object(__DIR__"obj/hustaff")->wield();
}

void do_alert(object me){
	object obj;
	object *inv;
	int i,j;
		
	inv=all_inventory(environment(this_object()));
	for (i=0;i<sizeof(inv);i++){
		if (inv[i]->query("prison_guard")) {
			inv[i]->kill_ob(me);
			j++;
			}
	}
	if (j<7)
	for(i=0; i<7-j; i++) {
		obj=new(__DIR__"guard2");
		obj->move(environment(this_object()));
		obj->kill_ob(me);
	}
	return;
}

void init()
{
        add_action("do_kill", "kill");
}

int do_kill(string arg){
	if (this_object()==present(arg,environment(this_object()))){
		do_alert(this_player());
	}
	return 0;
}