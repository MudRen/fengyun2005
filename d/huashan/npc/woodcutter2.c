// woodcutter.c
inherit NPC;
int milin();
void create()
{
        set_name("老樵夫", ({"woodcutter"}) );
        set("gender", "男性" );
        set("age", 66);
        set("agi",30);
        set("per", 10);
        
        set("long",
		"一个年轻的樵夫，由于常年的砍柴，使得他的一双手布满了老茧。\n"
		);
        set("combat_exp", 200000);
	set("inquiry", ([
			"milin" : (: milin :),
			"树林" : (: milin :),
			"密林" : (: milin :),
		]));
        set_skill("move", 250);
        set_skill("parry", 200);
	set_skill("dodge", 260);
        set_skill("axe",200);
	setup();
	carry_object("/obj/weapon/woodaxe")->wield();
	carry_object("/obj/armor/cloth")->wear();  
}

int milin(){
	object me;
	me = this_player();
	message_vision("$N抬头看了$n一眼道：“那片密林连我也走不出，每次都转回到这里，我看也只有
会飞的鸟才知道密林后面是什么。\n", this_object(), me);
	return 1;
}

