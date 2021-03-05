inherit ITEM;
#include <ansi.h>
void create()
{
    string *order=({"石雁","上官金虹","荆无命",HIY"天机老人"NOR,
    	"殷正廉","南宫灵","任慈","铁少","雪蕊儿","白三空","兴国大师","心树",
    	"天峰","葛伦","蓝天锤","箫王孙","石观音","白水娘娘",HIG"连城璧"NOR,
    	"卜战","蓝一尘","楚留香","枯梅大师","李玉函","柳无眉","王动","快活王",
    	"铁中棠","天枫十四郎","卢定关"});
	string letters;
	int i;
	set_name("紫檀木盒", ({ "purple box", "box" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("unit", "个");
		set("material", "wood");
		set("no_give",1);
		set("no_drop",1);
		set("no_split",1);
		set("no_burn",1);
		set("long","这是一个紫檀木盒，里面摆放着一叠厚厚的漆金请柬(Send)\n");
		set("annie/real_by_box",1);
		for (i=0; i<6; i++)
			order -= ({ order[random(sizeof(order))] });
		order += ({ "老刀把子","陆小凤" });

		set("letters",order);
	}
}

string long()
{ 
	int i;
	string msg;
	string *letters;
	letters=query("letters");
	msg=query("long");
	if (!sizeof(letters)) return msg;
	msg+="里面有：\n";
	for( i=0;i<sizeof(letters);i++)
		msg+="　　"+letters[i]+"的请柬(Letter)\n";
	return msg;
}

void init()
{
		add_action("do_sendmail","send");
}

int do_sendmail(string arg)
{
	int i;
	object me,master;
	string name,*letters;
	if(!arg) return notify_fail("用法：send letter to 某人\n");
	if (sscanf(arg, "letter to %s", name)!=1)
		return notify_fail("用法：send letter to 某人\n");
	me=this_player();
	if( !(master=present(name,environment(me))))
		return notify_fail("这里没有这个人。\n");
	letters=query("letters");
	for(i=0;i<sizeof(letters);i++)
		if( letters[i]==master->query("name") && !userp(master))	// annie. 
			{
				if(sizeof(letters)==1)
					letters=0;
				else if(i==0)
					letters=letters[1..sizeof(letters)-1];
				else
					letters=letters[0..i-1]+letters[i+1..sizeof(letters)-1];
				set("letters",letters);
				switch (random(3)){
				case 0:
				message_vision("$N抹了把汗,交给$n一封请柬。\n",me,master);
				break;
				case 1:
				message_vision("$N兴高采烈地交给$n一封请柬。\n",me, master);
				break;
				case 2:
				message_vision("$N恭恭敬敬地把一封请柬交给了$n。\n",me,master);
				}
				switch (master->query("name"))
				{
				case "定邦大师":
				case "参机大师":
				case "兴国大师":
 				case "葛伦"	:
				message_vision("$N微笑着点了点头,说道:这位施主，有劳了。\n",master);
				break;
				case "丁白云":
				case "雪蕊儿":
				message_vision("$N嫣然一笑：这位"+ RANK_D->query_respect(me)+",真是太谢谢你了。\n",master);
				break;
				case "上官金虹":
				case "西门吹雪":
				message_vision("$N仰天长笑：这一天终于来了。\n",master);
				break;
				case "快活王":
				message_vision("$N哼道：这叶老儿，竟然抢在老夫之前马踏中原。\n",master);
				break;
				break;
				case "丁乘风":
				case  "石雁":
				message_vision("$N叹了口气：这是何苦呢？你回去吧。\n",master);
				break;
				case "魏无牙": 
				case "老刀把子":
				case "羽天白" :
				case "裴冥通天":
				message_vision("$N阴阴的一笑，对$n说：“我知道了”。\n",master,me);
				break;
				break;
				case  HIY"东岳大帝"NOR:
				message_vision("$N笑道：“人间的聚会，也会想到我？真是生受了。\n",master);
				break;
				case  HIY"天机老人"NOR :
				message_vision("$N微笑着点了点头，叹了口气，“老了，老了”。\n",master);
				break;
				case  "查猛" :
				case  "蓝天锤" :
				message_vision("$N哈哈大笑，“叶老儿还记得老夫，一定去捧场。\n",master);
				break;
				case "石观音":
				case "水母阴姬":
				message_vision("$N对这封信好象兴趣不是很大，点了点头，就让$n退下了。\n",master,me);
				break;
				case "箫王孙":
				case "李寻欢":
				case "铁少" :
				message_vision("$N看完了这封信，对$n说：“回禀叶先生，若有空一定去，有劳这位"+RANK_D->query_respect(me)+"了。”\n",master,me);
				break;
				case "殷正廉":
				message_vision("$N皱着眉看完了信，沉思了一阵，挥手道：“本官知道了，你下去吧”。\n",master);
				break;
				default :
				switch(random(6)) 
						{
					case 0:
                        message_vision("$N长笑一声：天外飞仙，剑神一笑，这一天等得好苦啊！\n", master);
						break;
					case 1:
                        message_vision("$N沉吟道：月圆之夜，紫禁之巅，究竟谁是天下第一剑呢？\n",master);
						break;
					case 2:
						message_vision("$N冷哼一声，好象不屑一顾。\n", master);
						break;
					case 3:
                        message_vision("$N轻叹一声：宁静了数十年的江湖，又要开始大乱了么？叶孤城。。不简单啊。\n",master);
						break;
					case 4:
						message_vision("$N好象有心思一样，望着窗外，发起了呆。\n",master);
						break;
					case 5:
                        message_vision(CYN"$N皱眉道：某昨日夜观星像，紫微星光大暗，是否有大灾降世？\n"NOR, master);
						}
						
				}
				return 1;
			}
	return notify_fail("并没有给"+master->query("name")+"的请柬。\n");
}

/*
 
               (\~~~/)            
               ( ．．)        

               (_____)~．      
   
　　　　　　　- FengYun - 　　　
　　　　　　annie 10.2003
　　　dancing_faery@hotmail.com
*/
