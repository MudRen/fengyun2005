inherit NPC;
 
void do_drink();
 
void create()
{
        seteuid(getuid());
        set_name("账房先生", ({"xian sheng", "xian" }));
        set("long","一个精明能干，武功高强的账房先生。\n");
        set("gender","男性");

		set("con",20);
	
		set("force",1400);
		set("max_force",1400);
		
		set("str",50+ random(20));
	
        set("combat_exp", 9999999);
		set("no_heal",1);
	
		set("can_carry", 1);
        set_skill("unarmed", 100);
        set_skill("dodge", 100);
        set_skill("force", 130);
        set_skill("move",200);
	
        set_skill("qidaoforce", 100);
        set_skill("meihua-shou", 100);
        set_skill("fall-steps", 100);

		map_skill("move","fall-steps");
        map_skill("unarmed", "meihua-shou");
        map_skill("dodge", "fall-steps");

		set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.luoyeqiufeng" :),
        }) );

        set("chat_chance",30);
        set("chat_msg", ({
        	(: do_drink :), 
        }) );
        setup();
        carry_object(__DIR__"obj/jinzhuang")->wear();
}
 
 
void do_drink()
{
    	object *list, ob;
    	int i, can_drink;
    	this_object()->set("water",100);
    	list = all_inventory(this_object());
    	i = sizeof(list);
    	can_drink = 0;
    	while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol") {
            ob = list[i];
            can_drink = 1;
        }
    	}
    	if (can_drink) {
        	command("drink "+(string)ob->query("id"));
        	if ((int)ob->query("liquid/remaining") == 0)
            	command("drop wineskin");
    	}
    	else if (!random(10))
		message_vision("$N用力吸了吸那因为酗酒而发红的鼻子．\n", this_object());
    	return;
}
 
 
int accept_object(object who, object ob)
{
    if ((string)ob->query("liquid/type")=="alcohol") {
        if ((int)ob->query("liquid/remaining") == 0) {
            command("shake");
            command("say 空的我不要...");
            return 0;
        }
        else {
            command("smile");
            command("say 多谢!");
            return 1;
        }
    }
    else return 0;
}
 
