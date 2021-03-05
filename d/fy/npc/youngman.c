inherit NPC;
int random_action();
void create()
{
        set_name("年青人", ({ "young man","man" }) );
        set("gender", "男性" );
        set("age", random(5)+15);
        set("long", "一个单身的年青人，正盼着桃花运的降临。\n");
	set("per",30);
        set("combat_exp", 3000);
        set("attitude", "heroism");
        set_skill("unarmed", 20);
        set_skill("parry", 20);
	set_skill("dodge", 20);
      	set("chat_chance", 1);
        set("chat_msg", ({
                (: random_action :)
        }) );

	setup();
        carry_object("/obj/armor/cloth")->wear();
   
}

int random_action()
{
	switch(random(5)){
	case 0:
		command("smile");
		break;
	case 1:
		command("laugh");
		break;
	case 2:
		command("crazy");
		break;
		}
	return 1;
}
