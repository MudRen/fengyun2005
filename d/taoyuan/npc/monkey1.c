#include <ansi.h>

inherit NPC;
void create()
{
    	set_name("小猴子", ({ "monkey", "小猴子", "little monkey" }) );
    	set("race", "野兽");
    	set("age", 1);
    	set("gender", "雌性");
    	set("long", "小猴子用圆圆的充满好奇的眼上下打量着你，似乎在观察你的动作。
你也许可以教小猴子一些简单的动作。（ｔｅａｃｈ）\n");
    	set("attitude","peaceful");
    
    	set("chat_chance", 1);
    	set("chat_msg", ({
        	"小猴子抓了抓头。\n",
    	}) );
		set("can_carry", 1);
    	set("no_heal",1);
		set("agi", 50);
		set("per",30);
		set("str",30);
		set("combat_exp", 100000);
	
		set_skill("move",500);
    	set_skill("unarmed",400);
    	set_skill("dodge",500);
      
    	setup();
}

void init() {
	add_action("do_teach", "teach");
	add_action("do_kill","kill");
	add_action("do_fight","fight");
}

int do_kill(string arg)
{
	object me;
	me = this_player();
	if (arg !="monkey" && arg !="小猴子") 
	{	
		return 0;
	}else
	{
		if (this_object()->query_temp("is_unconcious"))
		{
			return 0;

		}else
		{
			message_vision("$N从地上抓起一把烂泥向$n扔一扔，做了一个鬼脸，飞奔而去。\n",this_object(),me);
			message_vision("$N被扔得满头满脸是泥，嗅了嗅，还臭臭的。\n",me);
			destruct(this_object());
			return 1;
		}

	}
}

int do_fight(string arg)
{
	object me;
	me = this_player();
	if (arg !="monkey" && arg !="小猴子") 
	{	
		return 0;
	}else
	{
		if (this_object()->query_temp("is_unconcious"))
		{
			return 0;

		}else
		{
			message_vision("$N从地上抓起一把烂泥向$n扔一扔，做了一个鬼脸，飞奔而去。\n",this_object(),me);
			message_vision("$N被扔得满头满脸是泥，嗅了嗅，还臭臭的。\n",me);
			destruct(this_object());
			return 1;
		}

	}

}

int do_teach(string arg) {
	string action, dest, act, obj;
	object ob, me, bb;
	int	result;
	
	me = this_player();
    if(!arg) {
  		return notify_fail("你要教谁什麽事？\n");	
	} else if(sscanf(arg, "monkey %s monkey", action) == 1) {
		dest = "monkey";
	} else if(sscanf(arg, "monkey %s", action) == 1 ) {

    } else {
        return notify_fail("你要教谁什麽事？\n");	
   	}
 	sscanf(action, "%s %s", act, obj);
//    write(sprintf("action is %s \ndest is %s\n act is %s\n", action, dest, act)); 
	result = me->ccommand(sprintf("%s %s", action, dest? dest : ""));
	if(act == "kill" || act == "go" || act == "vote") {
		message_vision("$N睁着大大的眼睛，呆呆的望着$n，似乎不明白你在做什么。\n",this_object(),me);
		return 1;
	}
	if(result) {
	    //if(time() - query("time") > 10) 
		if ( 1== 1)
		{
	        if( act == "wield" || act == "unwield" ) 
			{
				if( !present("bamboo", this_object()) ) 
				{
	                message_vision("$N抓耳挠腮的想了想，从灌木里拿出一块竹片。\n", this_object(), me);
	                bb = new(__DIR__"obj/zhupian");
	                bb->move(this_object());
	            }
	            ccommand(sprintf("%s zhu pian", act));
	            set("time", time());
	          
	        } else if (act == "eat")
	        {	
				message_vision("$N在灌木从中搜索了一阵，摸出一个野果咬了几口，又随手一扔。\n", this_object(), me);
	            set("time", time());
	        }else if (act == "drop")
	        {
				if( present("bamboo", this_object()) ) 
				{
					ccommand(sprintf("%s zhu pian", act));
	            }
	            set("time", time());
	        }else if (act == "drink")
	        {		
				object *list;
				int i, can_drink;
				//if ((int)this_object()->query("water") >= 380) 
				list = all_inventory(this_object());
				i = sizeof(list);
				can_drink = 0;
				while (i--) 
				{
					if ((string)list[i]->query("liquid/type") == "alcohol") 
					{
						ob = list[i];
						can_drink = 1;
					}
				}
				if (can_drink) 
				{
					command("drink "+(string)ob->query("id"));
					set("water",100);		// So it can drink more.
					if ((int)ob->query("liquid/remaining") == 0)
						command("drop " + ob->query("id"));
				}
				else 
					message_vision("$N找不到东西喝，急得抓耳挠腮！
\n", this_object());
				set("time", time());

	        }else{
	    	    ccommand(sprintf("%s %s", action, dest? me->query("id") : ""));
	            set("time", time());
	        }
	    } else {
	        message_vision("$N不耐烦地呲牙对着$n笑了笑。\n",this_object(), me);
	    }
	}
	return 1;
}

int accept_object(object who,object ob)
{
	
	object *list,obj;
	int i;
    list = all_inventory(this_object());
    i = sizeof(list);
    while (i--) {
        if ((string)list[i]->query("liquid/type") == "alcohol" && (int)list[i]->query("liquid/remaining") > 0) 
		{
            obj = list[i];
        }
    }
	if (obj)
	{
		message_vision("$N从怀中摸出了一个$n，指了指，一脸得意之色。\n",this_object(),obj);
		return 0;
	}
	if ((string)ob->query("liquid/type"))
	{
		if ((int)ob->query("liquid/remaining") == 0) 
		{
	        message_vision("$N拿起$n摇了摇，又听了听。一把扔了开去。\n",this_object(),ob);    
			//command("drop "+ob->query("id"));
			return 1;
		}

		if ((string)ob->query("liquid/type")!="alcohol")
		{
			
			message_vision("$N拿起$n拔开塞子，闻了闻。很不屑地一把扔了开去。\n",this_object(),ob);    
			//command("drop "+ob->query("id"));
			return 1;
        }
        else {
			message_vision("$N接过$n，嗅了嗅，喜地抓耳挠腮。\n",this_object(),ob);
            return 1;
        }

	}else return 0;
}

void die()
{
	object book;
	book = new(BOOKS"skill/animal-training_50");
	book-> move(environment(this_object()));
	message_vision("好象有什么从$N身上掉了下来。\n",this_object());
	::die();	
}

