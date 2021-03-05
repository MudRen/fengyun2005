#include <ansi.h>
inherit NPC;
#include <ansi.h>

int ask_for();
void create()
{
	set_name("宋甜儿", ({ "song tianer","song" }) );
 	set("title", "心灵手巧");
 	set("gender", "女性" );
 	set("age", 21);
 	set("per", 100);
 	set("long",
"穿着件鹅黄色的宽大衣裳，露出一双淡褐色的，均匀美丽，线条柔和的玉腿。
淡褐色的瓜子脸，配双黑白分明的大眼睛，显得又娇媚，又俏皮。\n");
 	set("combat_exp", 1500000);
 	set("chat_chance", 1);
 	set("chat_msg", ({
"宋甜儿噗哧一笑道：神水宫都无咩大不了喈，拒地够胆来，我地呢度有神醋宫既掌
门人李大小姐对付拒。 \n",
"宋甜儿目光幽怨，用半生不熟的官话道：楚大哥都走了快半个月了。。哎，要是能
让吃我亲手做的那道"RED"『斜阳倚翠红袖招』"NOR"就好了。。 \n",
        }) );
 	
 	set("attitude", "friendly");
 	set("inquiry", ([
        	"food" : (: ask_for :),
        	"斜阳倚翠红袖招" : (: ask_for :),

        ]));
 	setup();
    	carry_object(__DIR__"obj/yelskirt")->wear();
    	carry_object(__DIR__"obj/zhulan");
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object me)
{
	object basket,food;
	
	if(!me->query("food_carrier")) return ;
	if(me->query("food_carrier")+60>time())
	{
		message_vision(CYN"宋甜儿白了你一眼，说道：“唔使急，仲要等多阵。。 \n"NOR,me);
		remove_call_out("make_food");
		call_out("make_food",60+me->query("food_carrier")-time(),me);
		return ;
	}
    	message_vision(CYN "真系啊，去左边度啊？的菜都冻晒啦！ \n"NOR,me);
	basket=present("bamboo basket",this_object());
	if(!basket) 
	{
		basket=new(__DIR__"obj/zhulan");
		basket->move(this_object());
	}

    	message_vision(YEL "宋甜儿端上盘"RED"『斜阳倚翠红袖招』"YEL"放在翠竹篮中，小心翼翼交给你。 
\n宋甜儿撇撇嘴偷偷笑道：好啦，甘就麻烦你送俾我楚大哥啦，不过千其唔好偷吃喔。\n"NOR,me);
	food=new(__DIR__"obj/food");
	food->move(basket);			
	if (!basket->move(me))
		basket->move(environment(me));
	me->set_temp("song_food_carrier",1);
	me->delete("food_carrier");
	return ;
}



int ask_for()
{
	object me;
	
	me=this_player();	

	if (me->query_temp("song_food_carrier")) {
		message_vision("宋甜儿说：快点帮我去送俾楚大哥啦！\n", me);
		return 1;
	}
	
/*	if(me->query("marks/master_chu_food")) 
	{
		message_vision("宋甜儿对你一笑，用半生不熟的官话道：“多谢你上次帮我送菜给楚大哥。”\n",me);
		return 1;
	}*/
	
	if(me->query_temp("search_song_food"))
	{
        message_vision(CYN "宋甜儿向你做了一个鬼脸：仲唔快点帮我去揾材料？ 。。。\n"NOR,me);
		return 1;
	}

      	message_vision(YEL "宋甜儿拍手笑道：这位"+RANK_D->query_respect(me)+"愿帮我做这道" RED "『斜阳倚翠红袖招』" YEL "？那太好了， 
嗯，那听好了，我需要这些材料" GRN "「五彩小鱼」、「狼肉脯」、「绍兴女儿红」、
「水蜜桃」、「嫩藕」、「葱花」、「百合花」，" YEL "嗯，还有便是趵突泉的泉水 
，这就不劳您大驾了。\n"NOR, me);
    	message_vision(CYN "\n宋甜儿吐了吐舌头，做了个鬼脸道：快去快去！\n"NOR,me);
	me->set_temp("search_song_food",1);
	return 1;
}

string *material_names=({
    "五彩小鱼",YEL"狼肉脯"NOR,"绍兴女儿红","水蜜桃","嫩藕","葱花",HIC"百合花"NOR
	});

int accept_object(object me, object ob)
{
	string ob_name;
	int i,success,food_ok;
	
	if(!me->query_temp("search_song_food")) 
		return 0;
		
	ob_name=ob->query("name");
	success=1;
	food_ok=0;
	for(i=0;i<7;i++)
	{
		if(ob_name==material_names[i])
		{
			if(me->query_temp("song/"+ob_name))
			{
				message_vision("宋甜儿宛然一笑，说道：“呢个已经有晒啦。”\n",me);
				return 0;
			}
			me->set_temp("song/"+ob_name,1);
			message_vision("宋甜儿宛然一笑，说道：“多谢呢位"+RANK_D->query_respect(me)+"揾左"+ob_name+"俾我。”\n",me);
			food_ok=1;
		}
		success = success*me->query_temp("song/"+material_names[i]);
	}
	if(!success) return food_ok;
	command("jump "+me->query("id"));
    	message_vision(GRN "宋甜儿笑嘻嘻道：不错，不错，看我的。 \n"NOR,me);
    	message_vision(YEL"宋甜儿莲藕般的玉臂轻舒，眼花缭乱般摆弄了起来。。。。。 \n"NOR,me);
    	me->delete_temp("song");
    	me->set("food_carrier",time());
	call_out("make_food",60,me);
	return 1;
}


void make_food(object me)
{
	object food,basket;

	if(!present(me,environment()))
		return ;		
	basket = present("bamboo basket",this_object());
	if(!basket) 
	{
		basket=new(__DIR__"obj/zhulan");
		basket->move(this_object());
	}

    	message_vision( YEL "一柱香的功夫，宋甜儿端上盘" RED "『斜阳倚翠红袖招』" YEL "放在翠竹篮中，小心翼翼 
交给你。\n\n宋甜儿撇撇嘴偷偷笑道：好了，那就麻烦您送给我楚大哥，可千万别偷吃呦！ \n"NOR,me);
	food=new(__DIR__"obj/food");
	food->move(basket);			
	basket->move(me);
	me->set_temp("song_food_carrier",1);
    me->delete("food_carrier");
	return ;
}
		
