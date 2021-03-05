
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("采茶女", ({"girl", "caicha girl"}) );
        set("gender", "女性" );
        set("age",16+random(4));
        set("long", "正值芳龄的采茶女，忙碌地摘取茶树上的嫩叶。双手象对粉蝶儿，
轻柔的拂过嫩绿色的茶树。\n");
        set("attitude", "friendly");
        set("chat_chance", 1);
        set("no_arrest", 1);
        set("chat_msg", ({
		CYN"采茶女憧憬地说：“风云城里的女孩子打扮的可真漂亮啊，羡慕死我了。”\n"NOR,
        }) );
	setup();

	carry_object(__DIR__"obj/ycloth")->wear();
	carry_object(__DIR__"obj/shoe1")->wear();
	carry_object(__DIR__"obj/tea");
}

int accept_object(object who, object ob){
	object me, tea;
    	string  id;
    	int i;
   
   		me=this_player();
    	if( ob->name() == HIR"胭脂"NOR) {
	    	if(me->query("gender") == "男性" && (me->query("age") < 26 && me->query("age") > 18)) {
	    		message_vision("$N手里拿着" + ob->name() + "，一朵红云飞上双颊。\n", 
	            	     this_object(), me);     
	    	}
	        message_vision("$N腼腆的笑了笑说道：“多谢这位" + RANK_D->query_respect(me) + "”\n",
	        		this_object(), me);        	    	            
	    	tea=present("tea",this_object());
	    	if (tea) {    	
	    		message_vision("$N说：“我这儿有新采的茶叶，你拿些去尝尝鲜吧。”\n",this_object());
	    		if (!tea->move(me))
	    			destruct(tea);
	    		return 1;
	    	}
    	}
}

void die()
{
	object tea;
	if(tea=present("tea",this_object()))
	{
		message_vision(RED"\n鲜血从伤口流出，采茶女用迷茫的眼色看着你，缓缓向后倒下，嫩绿的茶叶染上\n"NOR,this_object());
		message_vision(RED"了血污，从采茶女的手中滑落，飘落在地上。\n"NOR, this_object());
		tea->set("long", "染上了血污的茶叶。\n");
		tea->set("名茶",0);
		tea->set("value", 20);
		tea->move(environment(this_object()));
	}	
	::die();
}