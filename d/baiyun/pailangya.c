//Sinny@fengyun 2003
//All Rights Reserved
#include <ansi.h>

inherit ROOM;
void create()
{
    set("short", "排浪崖");
    set("long", @LONG
但见浪涛不断地冲击着岩石，浪花飞溅，在阳光照射之下，发出千万金光，远方
也是光鳞万点，无涯无际，蔚为奇观。飒飒的海风把岩石上行人的衣袂，拂得猎猎有
声。这儿离海面约有三四十丈，极是高峭，身後虽还有更高的岩石峭壁，不过，当站
在这一块巨大的岩石上之时，除了天上的浮云比你更高之外，连海鸥也很少飞上来，
俯视着大海、浪花、海鸥……胸中豪情激荡，热血如沸。;
LONG
    );
    set("exits",
      ([
	"southup" : __DIR__"jintaoting",
	"northwest" : __DIR__"baiyunentrance",
	"east" : __DIR__"shiliang",
      ]));
    set("objects",
      ([
	//	     __DIR__"obj/sand" : 1,
      ]));
/*    set("item_desc", ([
	"岩石" : "这一大块岩石已被经年的浪花拍打的班班驳驳，但岩石上清晰可见数十个错落
有致的脚印，似乎象是一套步法，你可以按着脚印模仿着走一下。\n",
      "rock" : "这一大块岩石已被经年的浪花拍打的班班驳驳，但岩石上清晰可见数十个错落
有致的脚印，似乎象是一套步法，你可以按着脚印模仿着走一下。\n",
   ]));*/

    set("outdoors", "baiyun");
 	set("coor/x",10);
  	set("coor/y",-30);
	set("coor/z",0);
	setup();
}


void init()
{
//   add_action("do_imitate", "imitate");
}


int do_imitate(string arg)
{
        object me;
        int  s, amount, da, agi;
        if (this_player()->query("class")!="baiyun")
                return notify_fail("你胡乱的踩了几脚，什么也没能领会。。。。\n");
        me = this_player();
        if( me->is_fighting() )
                return notify_fail("在战斗中练习，想找死吗！\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能模仿。\n");
        s = (int)me->query_skill("feixian-steps", 1);
        agi = me->query_agi();
        if(agi == 10) {
                agi = agi + 2;
        }
        if( random(agi) >= 10) 
        {
                if(s >= 30)   {
                        message_vision(HIW "\n$N脚踩印记，疾行如风，无丝毫窒滞，飘忽若仙.\n"NOR, me);
                        tell_object(me, HIR"\n你的飞仙步法已经无法籍此精进了。\n"NOR);
                        return 1;
                } 
                da = 30*20/(me->query("dur")+me->query("fle"));
                if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
                {
                  return notify_fail("以你现在的状态，无法演练。\n");
                }
                if(s >= 0)   {
                        message_vision(HIW"\n$N脚踩印痕，若有所感，但觉与留下脚印的前人心意渐通，脚步也逐渐加快了起来。\n"NOR, me);
                } else    {
                        message_vision(HIW"\n$N脚踩印痕，却觉得分外别扭，不知该如何踏出下一步。\n"NOR, me);
                        }
                tell_object(me, HIY"你的飞仙步法长进了一些。\n"NOR);
                amount =  ((me->query("int") + me->query("cps"))*10);
                if(amount < 1) amount = 1;
                me->improve_skill("feixian-steps", amount);
                me->receive_damage("kee", da);
                me->receive_damage("gin", da);
                me->receive_damage("sen", da);  
        } else 
        {
          da = 200*20/(me->query("dur")+me->query("fle"));
          if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
          {
                  return notify_fail("以你现在的状态，无法演练。\n");
          }

          message_vision(BLU"\n$N脚踏印痕，海风却如重锤一般拍打而至，心神恍惚间，脚下一空，摔到在地。\n"NOR, me);
                me->receive_damage("kee", da);
                me->receive_damage("gin", da);
                me->receive_damage("sen", da);
                }
        me->start_busy(2);
        return 1;
}
