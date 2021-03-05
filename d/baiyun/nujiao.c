//Sinny@fengyun2003
//All Rights Reserved
#include <ansi.h>

inherit ROOM;
void create()
{
        set("short", "怒礁");
        set("long", @LONG
在整个白云岛中，唯独怒礁孑然傲立，值水涨之际，巨浪冲上外围的礁石，不住
发出使人心颤神荡，惊天巨响，不肯有一刻放缓下来。这里长年受狂风刮蚀，海水冲
刷，悬岩陡峭，石色赭赤的礁石巍然不动。走至怒礁尽头，但觉两耳风生，放眼则是
海天茫茫，怒浪惊涛中不时有几只海鸟翱翔搏击。怒浪，彩霞，青天、大海、鸥影、
孤帆，求索于天地之间，不禁怆然泣下。
LONG
           );
        set("exits",
            ([
        "west" : __DIR__"shiliang",
	    ]));
	set("objects",
 	   ([
        __DIR__"obj/rock" : 1,
        __DIR__"npc/baiyunxian" : 1,
	    ]));
      set("item_desc", ([
      "怒浪" : "怒浪地拍打着礁石，时而怒吼着，狂啸着，时而安静地如同处子一般，几只海鸥翱翔
搏击。怒浪，彩霞，青天、大海、鸥影、孤帆，你不由极目远眺，心有所思。\n",
      "巨浪" : "怒浪地拍打着礁石，时而怒吼着，狂啸着，时而安静地如同处子一般，几只海鸥翱翔
搏击。怒浪，彩霞，青天、大海、鸥影、孤帆，你不由极目远眺，心有所思。\n",
      "wave" : "怒浪地拍打着礁石，时而怒吼着，狂啸着，时而安静地如同处子一般，几只海鸥翱翔
搏击。怒浪，彩霞，青天、大海、鸥影、孤帆，你不由极目远眺，心有所思。\n",
   ]));

        set("outdoors", "baiyun");
	set("coor/x",0);
	set("coor/y",-1030);
	set("coor/z",0);
	setup();

}

void init()
{
//   add_action("do_watch", "watch");
}


int do_watch(string arg)
{
        object me;
        int  s, amount, da, spi;
        if (this_player()->query("class")!="baiyun")
                return notify_fail("你极目远眺，许久许久。。不知是泪水还是海水浸湿了双眼，一种莫名的感动
与伤怀充溢在胸。\n");
        me = this_player();
        if( me->is_fighting() )
                return notify_fail("在战斗中看海，太有闲情了吧！\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成，不能看海。\n");
        s = (int)me->query_skill("painting", 1);
        spi = me->query_spi();
        if(spi == 10) {
                spi = spi + 2;
        }
        if( random(spi) >= 10) 
        {
                if(s >= 150)   {
                        message_vision(HIC "\n$N极目远眺，良久，长叹一声，但觉天地在胸，所有一切仿佛萦绕在脑海中一般。\n"NOR, me);
                        tell_object(me, HIW"\n你的画道无法籍此修为了。\n"NOR);
                        return 1;
                } 
                if(s <= 120)   {
                        message_vision(HIW "\n$N极目远眺，许久许久。。不知是泪水还是海水浸湿了双眼，一种莫名的感动
充盈在胸，竟无法抑制感伤，失声痛哭。\n"NOR, me);
                        tell_object(me, HIW"\n你修为尚浅，无法以观海获得领悟。\n"NOR);
                        return 1;
                } 
                da = 30*20/(me->query("dur")+me->query("fle"));
                if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
                {
                  return notify_fail("以你现在的状态，无法观海。\n");
                }
                if(s >= 0)   {
                        message_vision(HIW"\n$N极目远眺，怒浪，彩霞，青天、大海、鸥影、孤帆。。。天地间的这一切壮阔
与苍茫，岂不就是一幅最美的画卷？\n"NOR, me);
                } else    {
                        message_vision(HIW"\n$N心中杂思甚多，何以静心以观海？\n"NOR, me);
                        }
                tell_object(me, HIY"你对画道似乎多了些领悟。\n"NOR);
                amount =  ((me->query("int") + me->query("spi"))*10);
                if(amount < 1) amount = 1;
                me->improve_skill("painting", amount);
                me->receive_damage("kee", da);
                me->receive_damage("gin", da);
                me->receive_damage("sen", da);  
        } else 
        {
          da = 200*20/(me->query("dur")+me->query("fle"));
          if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
          {
                  return notify_fail("以你现在的状态，无法静心观海。\n");
          }

          message_vision(BLU"\n海浪汹涌，狂风如刀，$N胆战心惊之下，站立不稳，滑倒在岩石上。\n"NOR, me);
                me->receive_damage("kee", da);
                me->receive_damage("gin", da);
                me->receive_damage("sen", da);
                }
        me->start_busy(3);
        return 1;
}
