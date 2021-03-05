#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void talk_show();

void create() {
	set_name( BLU"邪灵劍"NOR, ({ "sword" }) );
	set_weight(700);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "
邪灵剑据传是苗疆怪人楚天砼的佩剑，楚天砼行事亦正亦邪，一辈子没交过
一个朋友，没事时就对着此剑自言自语，长久长久，这剑也有了灵性。。。。\n");
		set("value", 3000);
		set("material", "steel");
		set("rigidity", 200);
		set("level_required",100);
		set("wield_msg", "$N从黑漆剑鞘中抽出一把$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n插入腰间的黑漆剑鞘。\n");
		set("equip_fun", (: talk_show() :));
	}
	::init_sword(70);
}


void talk_show(){
	
	string *msg;
	
	msg = ({ 
"邪灵剑尖声叫道：打劫！杀人！放火！\n",
"邪灵剑悄悄地告诉你：发财捷径----找个有钱人，宰了他，找个更有钱的，再宰了他。。。。\n",
"邪灵剑不耐烦地说：怎么慢慢吞吞的，ACTION！！！\n",
"邪灵剑认真地说：为了保持良好的杀人状态，我需要经常洗澡，才能血光焕发。\n",
"邪灵剑慢条斯理地说：嗯，需要什么忠告么？\n",
"邪灵剑郑重地说：别用我来砍柴，我不是斧子！\n",
"邪灵剑看了看四周说：宰了前面那个家伙？偶忍不住了，偶不见血不行了。。。\n",
"邪灵剑说：杀人了么？什么都行，小孩也行，小狗也行，天神也行？\n",
"邪灵剑说：作为一把剑，我的思维方式是非常平面化的。\n",
"邪灵剑朝你眨眨眼：你是不是很想一手一把邪灵剑?\n",
	});
	if (!random(10))
		write(CYN""+msg[random(sizeof(msg))]+""NOR);
}