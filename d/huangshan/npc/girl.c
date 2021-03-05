// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("小姑娘", ({"little girl", "girl"}) );
        set("gender", "女性" );
        set("age",5);
        set("long", "
小姑娘头扎两个冲天辫，粉红的脸蛋有如桃花瓣，水灵灵的大眼睛黑白分明。
可是一双眼睛有些微红，似乎刚哭过。不知道她是附近人家的孩子，还是跟
随父母来游山的客人。\n");
        set("attitude", "friendly");

        set("chat_chance", 1);
        set("no_arrest", 1);
        set("no_lu_letter",1);
        set("chat_msg", ({
		"小姑娘喃喃道：“我的毽子。。怎么一下子就不见了呢？” \n"
        }) );
	setup();

	carry_object(__DIR__"obj/jade")->wear();
	carry_object(__DIR__"obj/shoe")->wear();
	carry_object(__DIR__"obj/wcloth")->wear();
}


int kill_ob(object me){
    	message("vision", "一阵香味扑鼻，你只觉得头昏眼花，全身无力。\n",me);
    	message("vision", "你似乎看到小姑娘的手微微动了一下。\n", 
    		environment(), me);
    	me->unconcious();
	message_vision("$N转身离去，身影在树林中闪了几闪就不见了。\n", this_object());
    	destruct(this_object());
    	return 1;
}

int accept_object(object who, object ob){
//  	string  id;
  
    	if(ob->query("marks/toy")){
    		if( ob->name() == "毽子") {
    		message_vision("$N手里拿着" + ob->name() + "开心的跳了起来。\n", 
            	         this_object(), this_player());
			command("remove jade");
			command("give jade to " + who->get_id());
		} 
    	} else{
        	return notify_fail("小姑娘摇摇头说：“我不要这个。” \n");
    	}
    	call_out("leave", 1);
	return 1;
}

void leave() {
	message_vision("$N蹦蹦跳跳地跑了开去。\n", this_object());
	destruct(this_object());
}

void die()
{
	object jade;
	if(jade=present("yu pei",this_object()))
	{
		jade->set("mark/blood",1);
		jade->set("long","一个晶莹剔透的玉佩，玉佩上有一块淡红色的印记宛如桃花瓣。\n");
		message_vision("碧血飞溅有如落英，小姑娘缓缓倒下。几滴鲜红的血滴落在玉佩之上。\n",this_object());
		
	}	
	::die();
}

