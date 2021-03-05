#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "内室");
	set("long", @LONG
这是麦老广做烧鸭的厨房，也是他休息睡觉的地方，虽然屋中到处都是厚厚的
油腻，油烟把四壁熏得黑得跟锅底似的，一侧便是麦老广做烧鸭的灶台，不时飘出
令人忍不住流口水的香味，灶台上摆着几只大铁锅，都盖着木头盖子。
LONG);

	set("be_ambushed",1);
	set("type","indoors");
	set("exits",([
		"east":__DIR__"duckshop",
	]) );
	set("objects", ([
		__DIR__"obj/zaotai" : 1,
//		__DIR__"npc/feng":	1,
	]) );
	set("coor/x",0);
	set("coor/y",90);
	set("coor/z",0);
	setup();
}

int reset()
{
//	object feng;
	::reset();
	set("be_ambushed",1);
}

void init()
{
	object me;
	if(userp(me=this_player()))
	{
		remove_call_out("entering");
		call_out("entering",1,me);
	}
	add_action("do_get","get");
}

int entering(object me)
{
	object con, bot,zb,ky,ky1;
	object *inv;
	int i,j,k;
        object ob;    

        if (environment(me) != this_object())
        	return 1;
        if( userp(me) && (ob = present("feng qiwu", this_object())) 
        	&& me->query_temp("fugui_mai_showyaopai") ) 
        {
        	con = present("zaotai", this_object());
        	inv = all_inventory(con);
		if( !sizeof(inv))
		{
	    	bot  = new(__DIR__"obj/tieguo");
			ky1  = new(__DIR__"obj/kaoya1");
			zb=new(__DIR__"obj/xing");
			zb->move(ky1); 
			zb=new(__DIR__"obj/pearl");
			zb->move(ky1); 
			zb=new(__DIR__"obj/yuxi");
			zb->move(ky1); 
			zb=new(__DIR__"obj/pin");
			zb->move(ky1); 
			zb=new(__DIR__"obj/zhubao");
			zb->move(ky1); 
			j=random(5);
			for (i=0;i<j;i++)
			{	
				ky  = new(__DIR__"obj/kaoya");
				ky->move(bot); 
			}
			ky1->move(bot);
			k=random(5);
			for (i=0;i<k;i++)
			{	
				ky  = new(__DIR__"obj/kaoya");
				ky->move(bot); 
			}
			bot->move(con);
		}
                message_vision(HIR"黑暗中一个人突然如蚊龙出海、如鹞子翻身，其矫健轻捷，简直无法
用言语形容，一下便扣住$N的脉门，沉声道：“站住，否则要$N的命！
不错，我就是凤栖梧。看你命在旦夕，说给你知又有何妨。”\n"NOR,me);
               
		me->start_busy(3);
		me->delete_temp("fugui_mai_showyaopai");
		ob->kill_ob(me);
		me->kill_ob(ob);
	}	
	return 1;
}

int do_get(string arg)
{
	object jin, jia, fig;
	object me;
	string what,where;
	me=this_player();
	if(!arg) return 0;
	if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
	
	if (present("jin shizi",environment(this_player()))
			|| present("jia gun",environment(this_player()))
				|| present("figure",environment(this_player())))
	{
		write("现在还不是拿鸭子的时候！！\n");
		return 1;
	}
	
	if(where == "zaotai" || where == "灶台" )
	{
		if (present("feng qiwu", this_object())) 
		{
			message_vision("凤栖梧恶狠狠地瞪了$N一眼，$N吓得马上就把手缩了回去。\n\n"NOR,me);
   			return 1;
		}
		if (!this_player()->query_temp("marks/fugui_killed_feng"))
		{
			write("好香啊，真想拿来尝尝，不过，别人的东西还是不要乱拿了吧。\n");
			return 1;
		}
		if (query("be_ambushed"))
		{
			jin = new(__DIR__"npc/jinshizi");
			jia = new(__DIR__"npc/jiagun");
			fig = new(__DIR__"npc/meirujia");
			
			if (me && jin && jia && fig)
			{
				me->start_busy(10);
				set("be_ambushed",0);
				jin->set("chat_chance",0);
				jia->set("chat_chance",0);
				message_vision(CYN"$N突然听到身后有人大喝一声：且慢！，$N吓得马上就把手缩了回去。\n\n"NOR,me);
				if(environment(me) == this_object())
				{
        			jin->move(this_object());
        			message_vision("$N走了进来。\n",jin);
        			jia->move(this_object());
        			message_vision("$N走了进来。\n",jia);
        			fig->move(this_object());
        			message_vision("$N走了进来。\n",fig);
        		}
        		call_out("event",3,jin,jia,fig,me,0);
        		return 1;
			}
			return 0;
		}
	}
	return 0;		
}

void event(object jin,object jia,object fig,object me,int count)
{
	object room;
	room = this_object();
	
	if (present(jin,room) && present(jia,room) && present(fig,room) && present(me,room))
	{
		if (count == 0)
		{
		
			jin->ccommand("say 很好，现在案子总算破了。");
			jia->ccommand("sigh");
			jia->ccommand("say 原来麦老广就是凤栖梧，真是没有想到。");
			jin->ccommand("say 这人是凤栖梧的同伙，给我拿下。\n\n");
		}
		else if (count == 1)
		{
			me->ccommand("?");
			me->ccommand("say 难道，你们想。。。");
		}
		else if (count == 2)
		{
			jia->ccommand("grin jin");
			jia->ccommand("say 只要你一死，有谁知道我们已经破了凤栖梧的案子？");
			jin->ccommand("say 凤栖梧留下的那么多金银珠宝，我们自可以安然享用了。");
			jia->ccommand("say 小子，只好算你命不好了。\n\n");
			jin->ccommand("say 认命吧。");
			jin->set("immortal",1);
			jia->set("immortal",1);
			jin->set("force_factor",50);
			jia->set("force_factor",100);
			jin->kill_ob(me);
			jia->kill_ob(me);
			me->start_busy(10);
		}
		else if (count == 3)
		{
			jin->ccommand("say 南宫丑，你怎么还不动手？\n");
		}
		else if (count == 4)
		{
			message_vision(HIR"$N忽然闪电般的拔剑，你只觉眼前一闪，金狮子和夹棍竟都已倒下。\n\n"NOR,fig);
			jin->remove_all_killer();
			jia->remove_all_killer();
			jin->ccommand("say 你。。。居然。。。");
			message_vision(CYN"$N气的＇哇＇的一口吐出一滩鲜血。\n\n"NOR,jin);
		}
		else if (count == 5)
		{
			message_vision(CYN"$N冷冷的说道：“我不是南宫丑。”\n"NOR,fig);
			message_vision(CYN"$N说道：“我奉了提督大人之命，特来调查他们两个人是否有不法行为。”\n"NOR,fig);
		}
		else if (count == 6)
		{
			message_vision(CYN"$N说道：“现在我算是完成任务了，我要把他们押解走了。”\n\n"NOR,fig);
			message_vision(YEL"黑衣人一手提着金狮子，一手提着夹棍，转身离去。\n"NOR,me);
			
			REWARD_D->riddle_done( me, "智擒大盗", 20, 1);
			
			destruct(fig);
			destruct(jin);
			destruct(jia);
			return;
		}
		else 
			return;
	}
	else
	{
		if(jin) {
				message_vision(HIY"$N狂笑离去。\n"NOR,jin);
				destruct(jin);
			}
		if(jia) {
				message_vision(HIY"$N狂笑离去。\n"NOR,jia);
				destruct(jia);
			}
		if(fig) {
				message_vision(HIY"$N叹了口气，转身离去。\n"NOR,fig);
				destruct(fig);
			}
		return;
	}
	call_out("event",random(5),jin,jia,fig,me,count+1);
	return;
}

int valid_leave(object me)
{
	object room,jin,jia/*,fig*/;
	object mai;
	room=environment(me);
	if(mai=present("mai laoguang",room))
	{
		return notify_fail("凤栖梧拦住了你的去路！\n");
	}
	if(jin=present("jin shizi",room))
	{
		message_vision("$N拦住了你的去路，“想逃？没那么容易！”\n",jin);
		return notify_fail("等官差办完案再走吧！\n");
	}
	if(jia=present("jia gun",room))
	{
		message_vision("$N拦住了你的去路，“想逃？没那么容易！”\n",jia);
		return notify_fail("等官差办完案再走吧！\n");
	}
	return 1;
}