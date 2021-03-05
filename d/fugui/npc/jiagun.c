#include <ansi.h>
inherit NPC;
void create()
{
        set_name("夹棍", ({ "jia gun", "jiagun" }) );
        set("long",
                "夹棍是这一带有名的捕头，他的脸就好象只有皮包着骨头，既没有表
情，也没有肉。眼睛阴森森的，胆小的人在晚上见着他，非但实话要
被他逼出来，也许连屁都要被吓出来。\n");
    	set("chat_chance",1);
	set("chat_msg",	({
		"夹棍阴森森地望着你，冷冷道：“看告示，如果接我三招，就可拿到
腰牌，帮衙门捉拿凤栖梧归案，重重有赏。”\n",
	})  );

        set("combat_exp", 350000);
		
		set_skill("dodge",100);
		set_skill("move",100);
		set_skill("shenji-steps",80);
		set_skill("staff",100);
		set_skill("fumostaff",100);
		set_skill("parry",100);
	
		map_skill("staff","fumostaff");
		map_skill("dodge","shenji-steps");
		map_skill("move","shenji-steps");
			
		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/shawei")->wield();
}


void init(){
	::init();	
    	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_accept", "accept");
}


void heart_beat()
{
	object ob,me;
	
	if(me = query("test_target"))
	if(query("accept_test")==1)
	{
		say("\n夹棍点了点头，说道：很好，这是第一招....\n\n");
       		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
                
        	if( me->query_temp("last_damage_from") ==this_object() || !present(me, environment())) 
        	{
        		say("夹棍不屑地说道：连第一招都撑不过，真是太差了....\n");
                	delete("accept_test");
        	}
        	else add("accept_test",1);
       }
       else if(query("accept_test")==2)
       {
       	        say("\n夹棍说道：这是第二招....\n\n");
        	COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
        	if( me->query_temp("last_damage_from") ==this_object() || !present(me, environment())) 
        	{
			say("夹棍「哼」地一声，说道：这点功夫也敢出来混....\n");
                	delete("accept_test");
        	}
        	else add("accept_test",1);
        }
        else if(query("accept_test")==3)
        {
        	say("\n夹棍说道：第三招来了....\n\n");
        	COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
        	if( me->query_temp("last_damage_from") ==this_object() || !present(me, environment())) 
        	{
         		say("夹棍道：回去多练练吧....\n");
         	       	delete("accept_test");
        	}
        	else add("accept_test",1);
        }
        else if(query("accept_test")==4)
        {
                say("\n夹棍嘻嘻笑着说道：又有个得力的帮手了！\n\n");

       	ob = new(__DIR__"obj/yaopai");
		ob->move(me);

		write("夹棍给"+me->query("name")+"一个腰牌。");
		me->set_temp("yaopai",1);
		say("\n夹棍说道：你可以凭这个腰牌自由出入。给别人看看（ｓｈｏｗ）就知道你是协助办案的了。\n");
		say(HIG"夹棍说道：不想要的话，丢掉也没差，反正俺们哥儿俩是认得你了，这条山道随你来去。\n\n"NOR);
		delete("accept_test");
        }
        ::heart_beat();
}


int do_accept(){
    	mapping guild;
		object ob;
	        
    	if(!this_player()->query_temp("jiegaoshi")){
      		return 0;
    	}
		if(query("accept_test")){
			return notify_fail("夹棍正在忙，稍候一下。\n");
		}
    	set("accept_test",1);
    	set("test_target",this_player());
    	this_player()->delete_temp("jiegaoshi");
    	if( this_player()->query_temp("last_damage_from")) {
        	this_player()->delete_temp("last_damage_from");
    	}
		heart_beat();        
        return 1;
}

/*
void die(){
	object ob;
	object *enemy;
	
	ob = query_temp("last_damage_from");
	if(!ob) { 
		enemy = this_object()->query_enemy();
		if(sizeof(enemy))
			ob=enemy[0];
	} else {
		if(userp(ob)) { 	
			ob->set_temp("marks/killjia",1);
		}
	}
	::die();
}
				
*/