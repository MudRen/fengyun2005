// yellow.c
#include <ansi.h>
inherit NPC;
void create()
{       
        object armor;
        set_name(YEL"黄衣少女"NOR, ({ "yellow girl","girl" }) );
        set("long", "她身穿轻纱柔丝，白足如霜，青丝飘扬。\n");
        set("age", 16);
        set("gender", "女性");
        set("attitude", "peaceful");
        set("combat_exp", 500000);  
	
	set_skill("dodge",100);
	set_skill("parry",100);
	set_skill("move",100);
	set_skill("ill-quan",70);
	set_skill("tie-steps",70);
	set_skill("unarmed",100);
	
	map_skill("dodge","tie-steps");
	map_skill("unarmed","ill-quan");
	
        set("inquiry",([
        	"暗器" : "天下最厉害的暗器莫过于孔雀山庄的孔雀翎了。\n",
        	"孔雀山庄" : "孔雀山庄靠一支孔雀翎扬名天下，你可知道那孔雀翎已经丢失了吗？”\n",
        	"孔雀翎" : "孔雀翎虽失，孔雀图却流传在世，不知道在谁人的手中...\n",
            "peacock" :"孔雀翎虽失，孔雀图却流传在世，不知道在谁人的手中...\n",
            "孔雀图"  :"你如果能把孔雀图找来，我就给你做一个孔雀翎出来\n",
              ]) );
        set("chat_chance", 1);
        set("chat_msg", ({
                "黄衣少女说道：“你可知道天下最厉害的暗器是什么？”\n",
        }) );
        setup();
        armor=new(__DIR__"obj/corclot");
	armor->set_name(YEL"黄衣"NOR,({"yellow cloth","cloth"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corclasp");
	armor->set_name(YEL"黄镯"NOR,({"yellow bangle","bangle"}) );
	armor->move(this_object());
	armor->wear();	
	armor=new(__DIR__"obj/corgirt");
	armor->set_name(YEL"黄带"NOR,({"yellow belt","belt"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corhat");
	armor->set_name(YEL"黄帽"NOR,({"yellow hat","hat"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corboot");
	armor->set_name(YEL"黄鞋"NOR,({"yellow boot","boot"}) );
	armor->move(this_object());
	armor->wear();
	armor=new(__DIR__"obj/corribb");
	armor->set_name(YEL"黄巾"NOR,({"yellow ribbon","ribbon"}) );
	armor->move(this_object());
	armor->wear();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
   mixed foo;
   object *inv;
   object dress; 
   int i; 
     if (random(victim->query("combat_exp"))<100000) 
        {  
           inv = all_inventory(victim);
           if (sizeof(inv)==0) return;
           for (i=0;i<sizeof(inv);i++){
             dress=inv[i];
             if ((string)dress->query("equipped")=="worn" ) break;
            }
           if ((string)dress->query("equipped")=="worn" )
           {
                dress->unequip();
              victim->set_temp("mark/striped",1);     
              return victim->name()+YEL "身上的"+dress->name()+"被$N脱了下来。\n"NOR;
           } 
          };

            
           
        return;
}

int accept_object(object me, object obj)
{                                                                 
	object peacock;
    
    if( (string) obj->query("name") == "孔雀图" && obj->query("real"))
	{
		if (query_temp("making") || query_temp("maked"))
		{
			message_vision("$N叹了口气，说道：“我已经给别人做了一个了。”\n",this_object());
			return 0;
		}
		command("smile");
		message_vision("$N说道：“孔雀翎是用七七四十九片金叶子打制而成。”\n",this_object());
		me->set_temp("peacock",1);
		set_temp("making",me);
		return 1;
	}
		
	if( (string) obj->query("name") == "纯金叶子")
	{
		if(query_temp("making")!=me || !me->query_temp("peacock") || obj->query_amount()<49)
		{
			message_vision("$N说道：如此就多谢啦\n",this_object());
			return 1;
		}
 		if (me->query_temp("peacock")!=1)
		{
 			if(time()-(int) me->query_temp("peacock_time") < 300)
 				message_vision("$N嗔道：“别急嘛，人家还没做出来呢！”\n",this_object());
				
 			else
 			{
 				message_vision("$N说道：“好了好了终于做出来了，你瞧瞧。”\n",this_object());
 				message_vision("$N递给$n一个金筒\n",this_object(),me);
 				set_temp("maked",1);
 				delete_temp("making");        
 				me->delete_temp("peacock");
 				me->delete_temp("peacock_time");
 				peacock=new(__DIR__"obj/peacock");
 				peacock->set_temp("unused",1);
 				peacock->move(me);
 			}
		}
 		
 		else 
 		{
 			message_vision("$N说道：“我这就给你做，你等着。”\n",this_object());
 			me->set_temp("peacock",2);
 			me->set_temp("peacock_time",time());
 		}
 	}
 	else
 	{
	 	if(me->query_temp("peacock")==1 || query_temp("making")!=me || !me->query_temp("peacock") || (obj->value()<10000))
		{
			message_vision("$N说道：如此就多谢啦\n",this_object());
			return 1;
		}
 		if (me->query_temp("peacock")!=1 )
  			if(time()-(int) me->query_temp("peacock_time") < 300)
 				message_vision("$N嗔道：“别急嘛，人家还没做出来呢！”\n",this_object());
 			else
 			{
 				message_vision("$N说道：“好了好了终于做出来了，你瞧瞧。”\n",this_object());
 				message_vision("$N递给$n一个金筒\n",this_object(),me);
 				set_temp("maked",1);
 				delete_temp("making");
 				me->delete_temp("peacock");
 				me->delete_temp("peacock_time");
 				peacock=new(__DIR__"obj/peacock");
 				peacock->set_temp("unused",1);
 				peacock->move(me);
 			}
 		
 		else
 	    	return 1;
 	  }
 	  return 1;
}
 	
