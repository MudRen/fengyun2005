
inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "梅雨潭");
        set("long", @LONG
从山庄后院走出，山瀑愈来愈大，逐渐汇聚成湍急激荡的瀑布。四周竹林梅树
茂密，清幽宜人。每当风起之时，漫天水滴彷佛风中梅雨，秀丽无方，飞花碎玉般
乱溅。那溅着的水花，晶莹而多芒；远远望去，像一朵朵小小的白梅，微雨似的纷
纷落着。故此称之为梅雨瀑，而水流汇聚成汪汪一碧的梅雨潭。
LONG
        );
        set("exits", ([ 
  		"southup" : __DIR__"back_yard",
	]));
       set("objects", ([
        ]) );
        set("outdoors", "resort");
   	set("item_desc", ([
      	"梅雨瀑" : "梅雨瀑似撒落珍珠，似初夏梅雨，故称梅雨瀑。正值雨季，瀑布水流十分湍急。\n",
      	"waterfall" : "梅雨瀑似撒落珍珠，似初夏梅雨，故称梅雨瀑。正值雨季，瀑布水流十分湍急。\n",
   	]));
	set("resource/water", 1);
	set("liquid/container", "梅雨潭");
	set("liquid/name","梅雨潭水");
	set("tiexue_juhan",1);
	set("coor/x",0);
	set("coor/y",20);
	set("coor/z",-20);
	setup();
}

/*
void init()
{
   add_action("do_boji", "boji");
}


int do_boji(string arg)
{
   	object me;
   	int  s, amount, da, cor;
   	if (this_player()->query("class")!="legend")
   		return notify_fail("你什么也没领悟出来。。。。\n");
   	if(!arg || arg != "blade" ) return notify_fail("你要练习什么技能？\n");
   	me = this_player();
   	if( me->is_fighting() )
      		return notify_fail("在战斗中练习，想找死吗！\n");
   	if( me->is_busy() )
      		return notify_fail("你上一个动作还没有完成，不能搏击。\n");
   	s = (int)me->query_skill("blade", 1);
   	cor = me->query_cor();
   	if(cor == 10) {
		cor = cor + 2;
	}
   	if( random(cor) >= 10) 
   	{
      		if(s >= 100)   {
         		message_vision(HIC "\n$N飞身跃入梅雨瀑，屏气凝息，奋力与急流相抗。\n\n逆劈、横削、顺砍、倒刺只见$N无不驾轻就熟。\n"NOR, me);
         		tell_object(me, HIY"你的基本刀法已经无法籍此精进了。\n"NOR);
         		return 1;
      		} 
	  	da = 30*20/(me->query("dur")+me->query("fle"));
	  	if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
	  	{
		  return notify_fail("以你现在的状态，无法搏击。\n");
	  	}
      		if(s >= 0)   {
         		message_vision(HIC"\n$N飞身跃入梅雨瀑，屏气凝息，意守丹田。\n\n$N凝气守中，双足稳稳站定，奋力与激流搏击\n"NOR, me);
      		} else 	  {
         		message_vision(HIC"\n$N飞身跃入梅雨瀑，屏气凝息，奋力与急流相抗。\n\n但山瀑便冲得$N左摇右晃，难於站稳。\n"NOR, me);
      			}
      		tell_object(me, HIY"你的基本刀法长进了一些。\n"NOR);
      		amount =  ((me->query("int") + me->query("cps"))*10);
      		if(amount < 1) amount = 1;
      		me->improve_skill("blade", amount);
      		me->receive_damage("kee", da);
      		me->receive_damage("gin", da);
      		me->receive_damage("sen", da);  
   	} else 
   	{
	  da = 200*20/(me->query("dur")+me->query("fle"));
	  if (me->query("kee") - da <= 1 || me->query("gin") - da <= 1 || me->query("sen") - da <= 1)
	  {
		  return notify_fail("以你现在的状态，无法搏击。\n");
	  }

	  message_vision(CYN "\n$N双足一入水，但觉水流湍急异常无法立足，心头一阵害怕。\n"NOR, me);
     	  message_vision(CYN"\n$N脚下一虚，被激流冲上潭边。\n"NOR, me);
//      		write("da is"+(string)(da)+".\n");
      		me->receive_damage("kee", da);
      		me->receive_damage("gin", da);
      		me->receive_damage("sen", da);
   		}
   	me->start_busy(3);
   	return 1;
}
*/