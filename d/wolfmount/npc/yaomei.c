#include <ansi.h>
#include <command.h>
inherit NPC;

void create()
{
	set_name("柳幺妹", ({"liu yaomei","yaomei"}) );
        set("gender", "女性" );
        set("nickname", HIM"色狼"NOR);
        set("long", "这是一个萝衫半解，酥胸微露的美丽少女，色迷迷地盯着你。\n");
 		set("attitude", "friendly");
		set("age", 18+random(10));

        set("combat_exp", random(600000)+200000);
        create_family("狼山", 4, "弟子");
        set_skill("blade", 50+random(20));
        set_skill("parry", 50+random(20));
        set_skill("dodge", 50+random(20));
        set_skill("move", 50+random(20));
        set("chat_chance", 1);
        set("chat_msg", ({
        	"柳幺妹咯咯笑道：男人心里不就老琢磨那些事么，就让奴家陪大爷共度春宵吧！\n",
        }) );
        setup();
		carry_object(__DIR__"obj/pink_cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	object *inv;
	int i;
	if (!ob || environment(ob)!=environment(this_object()))	return;
		
	if ((string)ob->query("gender") == "男性")
	{
        message_vision(MAG"$N媚眼如丝盯着$n，双手摩挲着自己光滑的胸脯，梦呓般道：梦郎啊，来呀，
来呀，来和我共享云雨之乐。。。\n"NOR, this_object(),ob );
        if ((int)ob->query_cps()<random(15) && !ob->query_temp("sleeped")){
   			message_vision("$N不禁口水直流，糊里糊涂倒了下去。\n", ob);
			ob->set_temp("sleeped",1);
			ob->set_temp("disable_inputs",1);
			ob->add_temp("block_msg/all",1);
			ob->set_temp("is_unconcious",1);
			ob->set("disable_type",HIG "<睡梦中>"NOR);
			inv = all_inventory(ob);
			if(sizeof(inv)) {
				for(i=0; i<sizeof(inv); i++) {
					inv -= ({ 0 });
					if(sizeof(inv)) {
						if(inv[i]->query("equipped")) {
							inv[i]->unequip();
						}
					}
				}
			}
	  		call_out("wake", 8, ob);
	  		return;
	  	}
	  	else
	  	{
	  		message_vision("$N怒喝一声：妖女，滚开！\n", ob);
	  		return;
	  	}
	  }
	  return;
}


void wake(object ob)
{
	if (!ob)	return;
		
	ob->delete_temp("disable_inputs");
	ob->delete("disable_type");
	if (ob->query_temp("block_msg/all")>=1)
	    	ob->add_temp("block_msg/all", -1);
	ob->delete_temp("is_unconcious");
	if(!ob->is_ghost())
	{
        message_vision(CYN"$N睁开了眼睛，顿觉得身上凉嗖嗖的，低头一看，连内裤都没了。\n", ob); 
        message_vision("$N轻轻穿上箩裙，忸怩道：奴家什么都给了公子，公子你…可要对奴家负责呦。\n"NOR,this_object());
		return;
	}
	return;
}
