inherit NPC;

string desc();

void create()
{
	set_name("大水牛", ({ "bull" }) );
	set("race", "家畜");
	set("age", 3);
	set("long", (: desc :));

	set("chat_chance", 1);
	set("chat_msg", ({
		"哞~~~~~哞~~~~~\n",
		"大水牛没走几步，扑通一下跪在地上，看来是不行了。\n",
		"大水牛哀苦地看着你，似乎在向你求助。\n",
		
	}));
	set("combat_exp",20000);
	
	set_temp("apply/dodge", 100);
	set_temp("apply/attack", 100);	
	setup();
}


string desc(){
	string msg;
	
	if ( random(2))
		return "一条大公牛，无精打采地站着。\n";
	else
		return "一条大公牛，无精打采地站着，腿上有个脓疮，似乎是被什么毒物咬的，
是不是附近地上有什么。。。找找？\n";
}