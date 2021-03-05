//Created by justdoit at May 2001 
//All Rights Reserved ^_^

#include <ansi.h>
inherit NPC;  
void create()
{
    set_name("老狐狸", ({ "old fox","fox" }) );
	set("nickname", HIW "标标准准的"NOR);
	set("gender", "男性");
	set("no_arrest",1);
	set("age", 45);
    set("long","这是一个满脸风霜的老水手。\n");
	set("NO_KILL","杀了他怎么坐船去白云岛呢？\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
    set_skill("move",50);
    set_skill("dodge",60);
    set_skill("unarmed",60);
	set("attitude", "friendly");
    set("chat_chance", 2);
	set("chat_msg", 
	   ({
"老狐狸喃喃道：好地方，真是好地方啊……\n ",
	    }) );
	set("inquiry",
	   ([
	     "白云岛" : "据古老相传，白云岛在南边海域的群岛之中。\n",
	     "baiyundao" : "据古老相传，白云岛在南边海域的群岛之中。\n",
	     "好地方" : "只要你能想得出来的，那地方都有！从这里往西两步，再往北两步，左转就到了。\n",
	     "狐狸窝" : "只要你能想得出来的，那地方都有！从这里往西两步，再往北两步，左转就到了。\n",
	    ]) );	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

int accept_object(object who, object ob)
{
	object room;
	if ( !objectp(ob) ) return 0;
	if ( ob->query("name")=="租船的契约" )
	   {
	     if ( who->query("name")== ob->query("employer") )
	        { int boattype;
	          boattype=ob->query("shiptype");
	          switch( boattype ) 
	           {
		     case 0:
                 message_vision("老狐狸笑眯眯对$N说道：好，请随我来！\n", who);
                 tell_object(who, HIY "在老狐狸招呼声中，你一跃上了水手划来的小木筏上。\n\n"NOR ) ;
	             message_vision("老狐狸见$N上了木筏，对$N交待道：“这位客官，您只要一直往南划就可以到白云岛了。”\n", who);
	             message_vision("老狐狸跳入海水中，用力把木筏推入海中，对$N会了挥手，说道：“一路上多保重！”\n\n", who);
	             room = load_object("/d/baiyun/raft");
	             break;
		
		     case 1:
             message_vision("老狐狸把$N带到一艘结实耐用的小舟边，说道：这位"+RANK_D->query_respect(who)+
			       "请上船，如果要去白云岛请往南划！\n",who);
             tell_object(who, HIY "你轻轻跳上了微微晃动的小舟上。\n\n"NOR );
		     room = load_object("/d/baiyun/boat");
		     break;
 		
                     case 2:
//		     message_vision("老狐狸把$N带到一艘高桅、坚固、耐用的大海船边，说道：这位"+RANK_D->query_respect(who)+
//			       "请上船，如果要去白云岛请命令水手们往南划！\n",who);
		     message_vision("老狐狸挠挠满头白发，苦笑道：大海船自从载上次那个四条眉毛的爷出海后，就再也没回来过。哎。。\n",who);
				return 0;
//
//		     tell_object(who, HIY "你得意洋洋、大摇大摆的上了船.......\n"NOR );
//		     room = load_object("/d/baiyun/seaship");
		     break;
	           }
	          who->move(room);
	          return 1;
	        }
	     else if ( who->query("name")!= ob->query("employer") )
	           {
	             message_vision("老狐狸拍了拍$N的肩膀，狡猾的笑道：“这位客官，这可不是您本人与船行签订的契约！在下无法为您服务。”\n",who);
	             return 1;
	           }
	   }
	else if ( who->query("gender") == "男性" )
	   {
	     message_vision("$N用长满了老茧的手，用力拍着$n的肩，笑眯眯地对你耳语道：
“我可以介绍个好地方给你，到了那里，说不定你就不想走了。”\n\n",this_object(),who);
	     return 1;
	   }
}


/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
