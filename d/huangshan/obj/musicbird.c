
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("棕嗓鹛", ({ "music bird","bird" }) );
        set("race", "飞禽");
        set("age", 5);
        set("long", "棕嗓鹛的鸣声悦耳动听，丰富多变，叫时能连发三四或七八个音节，
如歌唱弹琴。 \n");
        set("max_kee", 5);
        set("spi", 100);
    	set("chat_chance", 1);
    	set("chat_msg", ({
        "棕嗓鹛唱道：百鸟喧啾正倦听，忽然闻此独关情。\n",
        "棕嗓鹛唱道：声随鱼板常三奏，节合箫韶应九成。\n",
        "棕嗓鹛唱道：窗外晓飞僧梦断，岩前时见客心清。\n",
        "棕嗓鹛唱道：禅林得汝添奇玩，故向祗园久著名。\n", 
            }) );       	

        set_skill("dodge", 150);

        setup();
}


int kill_ob(object me)
{
	message_vision("$N机灵地跳在一边，一展翅膀，忽的飞走了。 \n",this_object());
	destruct(this_object());

	return 1;
}


string *event1_msg=	({
	"棕嗓鹛惊叫了起来，它挣扎了几下，没有挣脱。 
它偏着头，带着惊恐的眼神看了你一会儿。 \n",
	"棕嗓鹛忽然说起话来，声音就像是一位少女： 
“我不是一只一般的鸟。我是有神奇能力的精灵。” \n",

	"你从来没听过这样悦耳的声音，看着手里的棕嗓鹛一时有点发呆。 \n",

	"棕嗓鹛接着说：“因为我有神奇的能力，所以我可以给你两个 
对你永远有用的忠告，只求你能放了我。” \n",

	"你心中一动，对棕嗓鹛点了点头。 \n",

	"棕嗓鹛说：“第一条忠告是：如果你认为不可能的事，别人怎么说 
你也不要相信。” \n",

	"她接着说：“第二条忠告是：无论什么事，你做了以后都不要后悔。” \n",

	"你听了以后，觉得深有所感。棕嗓鹛银铃般的声音似乎还回旋在 
耳边。你回想以往的经历，不由长叹一声，松开了手。 \n",
	});


void event1(object me, int count)
{
	tell_object(me,event1_msg[count]+"\n");
	if(++count==sizeof(event1_msg))
	{
		this_object()->move(environment(me));
		this_object()->set("escaping",1);
		call_out("event2",1,me);
	}
	else call_out("event1",1,me,count);
	return ;
}
	
void event2(object me)
{
	
	message_vision("棕嗓鹛一展翅膀，飞上高处的松枝。侧头看了看$N，发出一阵 
轻脆的笑声：“你真是错过了千载难逢的好机会。我这么聪明， 
是因为我嘴里含了一块天灵翡翠，是它赐予我智慧，才骗过你 
的。真可惜如此宝物，你失之交臂。” \n\n",me);
	message_vision("棕嗓鹛咯咯娇笑起来。 \n",me);
	me->set_temp("mbescape",1);
	return ;
}


string *event3_msg= ({
	"棕嗓鹛忽然从树上飞了下来，就停在$N伸手可及的地方。但$N连一个指头也伸不动了。 \n",
	"棕嗓鹛着对$N说：“我给你的忠告看来都没有用。” 
“我告诉你，如果你认为不可能的事，别人怎么说你也不要相信。 
我这么小，嘴里含得下天灵翡翠吗？可你就偏偏信了。” \n",

	"“我告诉你，无论什么事，你做了以后都不要后悔。可你又后悔 
放了我，为了抓我摔成这个样子。” \n",

   	"棕嗓鹛叹了口气。“人心啊，人心啊...” \n",
    
   	"棕嗓鹛飞向远方，她的叹气声似乎永远留在你耳边。 \n",
  });

void event3(object me, int count)
{
	message_vision(event3_msg[count]+"\n",me);
	if(++count==sizeof(event3_msg))
		destruct(this_object());
	else call_out("event3",1,me,count);
	return ;
}


int imbue_event(object me, object room){
	object weapon, ob, *inv, obj;
	string prop;
	int i;
	mapping data;
	
	if(!interactive(me) || environment(me) != room) {
		return 0;
	}

	obj = me->query_temp("weapon");
	if(objectp(obj) && obj->query("owner")) {
		weapon = me->query_temp("weapon");
	} else { 
		inv = all_inventory(me);	
		for(i=0; i<sizeof(inv); i++) {
			if(inv[i]->query("weapon_prop") && inv[i]->query("owner")) {
				weapon = inv[i];
				break;
			}
		}	
	}
	if(!objectp(weapon)){
		if(!objectp(obj)) {
			message_vision(HIB"\n随着棕嗓鹛的远飞，悦耳的笑声似乎一丝丝在空气中化开。\n"NOR, me);
		} else {
			message_vision(HIB"\n随着棕嗓鹛的远飞，悦耳的笑声似乎一丝丝在空气中化开。\n"NOR, me);
		}
	}else{
		message_vision(HIB"\n随着棕嗓鹛的远飞，悦耳的笑声似乎一丝丝在空气中化开。\n"NOR, me);
		message_vision(HIB"$N手中的" + weapon->name() + HIB"伴随着悦耳的笑声发出阵阵清越的龙鸣之声。\n"NOR, me);
		message_vision(HIB"随着笑声的淡去，龙鸣声亦渐渐隐去。\n"NOR, me);
	}
	
	data = ([
		"name":		"棕嗓鹛之歌",
		"target":	me,
		"att_1":	"int",
		"att_1c":	1,
		"mark":		1,
	]);
	REWARD_D->imbue_att(data);	
	
}

void event4(object me){
	
	if(!me ||!living(me)){
		return ;
	}
	this_object()->move(environment(me));
	message_vision(HIG"棕嗓鹛忽然从树上飞了下来，在$N头顶盘旋飞舞。 
棕嗓鹛笑着对$N说：“你真是一个做事不悔的人。” 
棕嗓鹛娇笑道：“天灵翡翠确有其物，它在草木繁盛的地方，有缘的话你就会找到它。” 
棕嗓鹛飞向远方。\n"NOR,me);
	me->start_busy(3);
	tell_object(me, "\n你眼前雾气闪动，似乎看到了什么迷离的景色。
"BGRN+HIG"
    靠近草地的边缘长着一棵枝叶繁茂的小树，树下是碧绿的草地，一块平整的大
石头压在草地上，几朵黄色的小花开在石头的旁边。夏日时一阵阵的小凉风吹来让
人暑意全消，是一个纳凉的好地方。"NOR" 
	
雾消云散，一切似乎是场梦境。\n");
	
	if(!REWARD_D->imbue_check(me,"棕嗓鹛之歌")){
		imbue_event(me, environment(me));
	
		if (!REWARD_D->check_m_success(me,"棕嗓鹛之歌"))
		{
			REWARD_D->riddle_done(me,"棕嗓鹛之歌",100,1);
		}	
	} 
	
	destruct(this_object());

}