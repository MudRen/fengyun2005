#include <ansi.h>
inherit NPC;
void make_makeup(object me);
int ask_for();
void create()
{
 	set_name("苏蓉蓉", ({ "su rongrong","su" }) );
 	set("title", "红颜知己");
 	set("gender", "女性" );
 	set("age", 21);
 	set("per", 100);
 	set("long",
"穿着件柔软而宽大的长裙，满天斜阳映着她松松的发髻，清澈的湖水也映着
她那温柔的笑容，看来就像是天上的仙子，久已不食人间烟火。据说苏蓉蓉
的大哥便是当年惊才绝艳的小神童，而苏蓉蓉制造面具（ｍａｓｋ）的功夫
也早已青出于蓝。\n");
 	set("combat_exp", 80000);
 	set("chat_chance", 1);
 	set("chat_msg", ({
		"苏蓉蓉随手采了个莲蓬，幽幽道：不知楚大哥这趟蝙蝠岛之行怎么样了？天气转
冷了，真该叫他多带些衣服。\n",
		"苏蓉蓉嫣然笑道：盗帅夜留香，销魂不知在何方？又得我在四处留香了。。。\n",
        }) );
 	
 	set("attitude", "friendly");
  	set("inquiry", ([
        	"mask" : (: ask_for :),
        	"面具" : (: ask_for :),

        ]));
 	setup();
    	carry_object(__DIR__"obj/changbao")->wear();
    	carry_object(__DIR__"obj/lotuspetal");
}


void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_answer","answer");
}

void greeting(object me)
{
//	object basket,food;
	
	if(!me->query("makeup_buyer")) return ;
	if(me->query("makeup_buyer")+60>time())
	{
		message_vision(CYN"苏蓉蓉白了你一眼，说道：“别急，还要再等一会。。\n"NOR,me);
		remove_call_out("make_makeup");
		call_out("make_makeup",60+me->query("makeup_buyer")-time(),me);
		return ;
	}
    message_vision(CYN "苏蓉蓉白了你一眼，说道：真是的，跑哪里去了？。。。\n"NOR,me);
	make_makeup(me);
	return ;
}



int ask_for()
{
	object me;
	
	me=this_player();	
	if(me->query("mark/su_makeup"))
	if(me->query("mark/su_makeup")+600<time()) 
	{
		message_vision("苏蓉蓉对你一笑：“不好意思，现在我太累了，过会再来吧。”\n",me);
		return 1;
	}
	if(me->query_temp("search_su_makeup"))
	{
        message_vision(CYN "苏蓉蓉莞尔一笑：实在没法子，缺了一样就没法做出最好的面具。。。 \n"NOR,me);
		return 1;
	}

      message_vision(CYN "苏蓉蓉美目流转，柔声道：这做面具虽说只是皮毛小道，难登大雅，不过着 
实也很花力气，如果你找到了"YEL"小鹿的「茸毛」、菜花蛇过冬褪去的「蛇皮」、 
「小鸟蛋」的蛋清、一根「绣花针」、「藤萝绳」的丝、「桃花瓣」的花粉，
还需要一支「狼毫笔」做画，"CYN"我或许可以试试看。 \n"NOR, me);

	me->set_temp("search_su_makeup",1);
	return 1;
}

string *material_names=({
    "茸毛","菜花蛇皮","小鸟蛋","绣花针","桃花瓣",WHT"狼毫笔"NOR,"藤萝绳"
	});

int accept_object(object me, object ob)
{
	string ob_name;
	int i,success,makeup_ok;
	
	if(!me->query_temp("search_su_makeup")) 
		return 0;
		
	ob_name=ob->query("name");
	success=1;
	makeup_ok=0;
	for(i=0;i<7;i++)
	{
		if(ob_name==material_names[i])
		{
			if(me->query_temp("su/"+ob_name))
			{
				message_vision("苏蓉蓉宛然一笑，说道：“这个材料已经有了呢。”\n",me);
				return 0;
			}
			me->set_temp("su/"+ob_name,1);
			message_vision("苏蓉蓉宛然一笑，说道：“多谢这位"+RANK_D->query_respect(me)+"为我找来"+ob_name+"。”\n",me);
			makeup_ok=1;
		}
		success=success*me->query_temp("su/"+material_names[i]);
	}
	if(!success) return makeup_ok; 
	tell_object(me,"请问你想要做谁的面具呢？(answer id)\n");
	set("answer_person",me);
	me->delete_temp("search_su_makeup");
	return 1;
}

int do_answer(string arg)
{
	object me,target;
	
	me=this_player();
	if(me!=query("answer_person")) return 0;
	target=find_living(arg);
	if(!target || (target && target->query("wiz_invis")))
	{
		tell_object(me,"你说的这个人不存在呀。。。\n");
		return 1;
	}
	me->set("make_makeup_for/id",target->query("id"));
	me->set("make_makeup_for/name",target->query("name"));
	me->set("make_makeup_for/short",target->short());
	me->set("make_makeup_for/long",target->long());
	message_vision(GRN "苏蓉蓉满意地点点头，轻声道：我试着做一个"+target->query("name")+"的面具看看。。。 \n"NOR,me);
    	message_vision(YEL"苏蓉蓉聚精会神，小心翼翼地开始做起面具来。。。  \n"NOR,me);
    	me->set("makeup_buyer",time());
	call_out("make_makeup",6,me);
	return 1;
}


void make_makeup(object me)
{
	object makeup/*,pozhi*/;
	
	if(!present(me,environment()))
		return ;		


	makeup=new(__DIR__"obj/skinmask");
	makeup->set("armor_prop/id", ({capitalize(me->query("make_makeup_for/id"))}) );
	makeup->set("armor_prop/name", ({me->query("make_makeup_for/name")}) );
	makeup->set("armor_prop/short", ({me->query("make_makeup_for/short")}) );
	makeup->set("armor_prop/long",({me->query("make_makeup_for/long")}) );

	
    message_vision( CYN "一盏茶功夫，苏蓉蓉擦了擦额头的香汗，微笑道：做好了，幸好这手艺没 
怎么忘。。 

  苏蓉蓉给$N一个精致的面具。  \n"NOR,me);
	me->delete_temp("su");
	me->delete("makeup_buyer");
	me->set("mark/su_makeup",time());
	makeup->move(me);

/*  message_vision( CYN "一盏茶功夫，苏蓉蓉擦了擦额头的香汗，看着手里做坏了的面具，\n愁眉苦脸的说：自从那次笑笑来过把我灌醉之后，我就再没做成过面具．．．\n"NOR,me);
    ccommand("say 你还是去找城里的芳儿吧。"); 
    pozhi = new("/d/fy/npc/obj/pozhi");
    pozhi->set("value",1);
    pozhi->move(this_object());
    ccommand("give pozhi to "+me->get_id());*/
    
    me->delete_temp("su");
    me->delete("makeup_buyer");
    me->set("mark/su_makeup",time());
	return ;
}
		