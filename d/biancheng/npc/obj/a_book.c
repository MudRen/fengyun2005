inherit ITEM;
void create()
{
        set_name("素女经", ({ "sunvjing" }));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long","
据后人考证，素女经可能是在战国至两汉之间完成，并在魏晋六朝民间流传
修改的。书名最早出现在晋朝葛洪所著的《抱朴子内篇.遐览》中,作者不详。
此书原已失传，但后来发现东瀛丹波康赖于982年编成的《医心方》一书中曾
收集此书，现在人们所见到的《素女经》就是《医心方》所收集而经清代人
叶德辉辑入《双梅景暗丛书》。\n" );
                set("value", 260);
                set("material", "paper");
        }
	::init_item();
}

void init()
{
  	if(this_player()==environment())
  		add_action("do_study","study");
}


int do_study(string arg)
{
        object me,ob;
	int sena;
	int cps;
	string book;
	string *content = ({
"
黄帝问素女曰：“吾气衰而不和，心内不乐，身常恐危，将如之何？”
素女曰：“凡人之所以衰微者，皆伤于阴阳交接之道尔。夫女之胜男，犹水之
灭火。知行之，如釜鼎能和五味，以成羹霍。能知阴阳之道，悉成五乐；不知
之者，身命将夭，何得欢乐？可不慎哉！\n\n",
"
素女曰：“有采女者，妙得道术。王使采女问：彭祖延年益寿之法，彭祖曰：
“爱精养神，服食众药，可得长生。然不知交接之道，虽服药无益也。男女相
成，犹天地相生也。天地得交会之道，故无终竟之限。人失交接之道，故有夭
折之渐，能避渐伤之事而得阴阳之术，则不死之道也。”\n\n",
"
黄帝曰：“夫阴阳交接，节度为之奈何？”素女曰：“交接之道，故有形状，
男致不衰，女除百病，心意娱乐，气力强。然不知行者，渐以衰损。欲知其道，
在于定气、安心、和志。三气皆至，神明统归，不寒不热，不饥不饱，宁身定
体，性必舒迟，浅内徐动，出入欲希。女快意，男盛不衰，以此为节。”\n\n",
});		

        me = this_player();
	cps = random((int)me->query("cps"));
       if(!arg || sscanf(arg, "%s %d", book, sena)!=2 )
                return notify_fail("指令格式：study <书> <神数量>\n");
        if( (string) book != "sunvjing")
                return notify_fail("你要读什麽？\n");
        if(!objectp(ob = present(book, me)) )
                return notify_fail("你要读什麽？\n");
       switch( random(3) ) {
                case 0:
        message("vision", me->name() + "正欣喜若狂地翻读着" + ob->name()
                + "。\n", environment(me), me);
                        break;
                case 1:
        message("vision", me->name() + "翻了一页" + ob->name()
                + "，抬起头用色迷迷眼神上上下下的打量着你。\n", environment(me), me);
                        break;
                case 2:
        message("vision", me->name() + "飞快地翻读着" + ob->name()
                + "，＂啪＂的一声，一滴口水滴在书上。\n", environment(me), me);
                        break;
        }
		write(content[random(sizeof(content))]);
	if( cps >20 )
	{	write("你越读越想读．．．\n");
		return 1;
	}
	if( cps >15)
        {       write("你感到全身发热，越读越想读．．．\n");
                return 1;
        }
		write("你感到一股热气从丹田直升而起．．．\n");
		me->unconcious();
		return 1;
}


