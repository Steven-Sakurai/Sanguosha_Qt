#-------------------------------------------------
#
# Project created by QtCreator 2016-12-16T18:50:34
#
#-------------------------------------------------

QT       += core gui
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sanguosha

TEMPLATE = app
CONFIG -= console

INCLUDEPATH += $$PWD/include/
INCLUDEPATH += $$PWD/src/
HEADERS += build/ui_mainwindow.h \
           include/Axe.h \
           include/Card.h \
           include/CardFilter.h \
           include/CardInfo.h \
           include/CardType.h \
           include/Cheat.h \
           include/CiXiongSword.h \
           include/ClientPlayer.h \
           include/ConsolePlayer.h \
           include/CounterCard.h \
           include/CounterEvent.h \
           include/CrossBow.h \
           include/DamageEvent.h \
           include/DeathEvent.h \
           include/DefensiveHorse.h \
           include/DelayedTrick.h \
           include/DiscardEvent.h \
           include/Dismantle.h \
           include/Divination.h \
           include/Dodge.h \
           include/Duel.h \
           include/DyingEvent.h \
           include/EightDiagram.h \
           include/EquipCard.h \
           include/Event.h \
           include/EventBegin.h \
           include/EventEnd.h \
           include/Friendship.h \
           include/Game.h \
           include/GamePointer.h \
           include/Halberd.h \
           include/Harvest.h \
           include/HpReductionEvent.h \
           include/IceSword.h \
           include/JudgeEvent.h \
           include/Lib.h \
           include/Lightning.h \
           include/mainwindow.h \
           include/MoveEvent.h \
           include/MoveStruct.h \
           include/MoveVisibilityEffect.h \
           include/NeedUseEvent.h \
           include/NeedYieldEvent.h \
           include/NonEquipCard.h \
           include/OffensiveHorse.h \
           include/Peach.h \
           include/PhaseEvent.h \
           include/Player.h \
           include/PreUseStruct.h \
           include/PrimitiveEvent.h \
           include/PrimitiveMoveEvent.h \
           include/QiLinBow.h \
           include/RandomShot.h \
           include/RecoverEvent.h \
           include/RegisterSkillEffect.h \
           include/RemoveSkillEffect.h \
           include/RenWangShield.h \
           include/ResolveEvent.h \
           include/SkillEffect.h \
           include/Slash.h \
           include/SouthernIntruder.h \
           include/Spear.h \
           include/Static.h \
           include/TargetStruct.h \
           include/Thievery.h \
           include/TimeWalk.h \
           include/Transform.h \
           include/Trigger.h \
           include/TurnEvent.h \
           include/UseEvent.h \
           include/UseStruct.h \
           include/ValueChangeEvent.h \
           include/WeaponCard.h \
           include/WeaponGambit.h \
           include/YieldEvent.h \
           include/Zone.h
FORMS += mainwindow.ui
SOURCES += src/Axe.cpp \
           src/Card.cpp \
           src/CardInfo.cpp \
           src/CardType.cpp \
           src/Cheat.cpp \
           src/CiXiongSword.cpp \
           src/ClientPlayer.cpp \
           src/ConsolePlayer.cpp \
           src/CounterCard.cpp \
           src/CounterEvent.cpp \
           src/CrossBow.cpp \
           src/DamageEvent.cpp \
           src/DeathEvent.cpp \
           src/DefensiveHorse.cpp \
           src/DelayedTrick.cpp \
           src/DiscardEvent.cpp \
           src/Dismantle.cpp \
           src/Divination.cpp \
           src/Dodge.cpp \
           src/Duel.cpp \
           src/DyingEvent.cpp \
           src/EightDiagram.cpp \
           src/EquipCard.cpp \
           src/Event.cpp \
           src/EventBegin.cpp \
           src/EventEnd.cpp \
           src/Exception.cpp \
           src/Friendship.cpp \
           src/Game.cpp \
           src/Halberd.cpp \
           src/Harvest.cpp \
           src/HpReductionEvent.cpp \
           src/IceSword.cpp \
           src/JudgeEvent.cpp \
           src/Lightning.cpp \
           src/main.cpp \
           src/mainwindow.cpp \
           src/MoveEvent.cpp \
           src/MoveStruct.cpp \
           src/MoveVisibilityEffect.cpp \
           src/NeedUseEvent.cpp \
           src/NeedYieldEvent.cpp \
           src/NonEquipCard.cpp \
           src/OffensiveHorse.cpp \
           src/Peach.cpp \
           src/PhaseEvent.cpp \
           src/Player.cpp \
           src/PreUseStruct.cpp \
           src/PrimitiveEvent.cpp \
           src/PrimitiveMoveEvent.cpp \
           src/QiLinBow.cpp \
           src/RandomShot.cpp \
           src/RecoverEvent.cpp \
           src/RegisterSkillEffect.cpp \
           src/RemoveSkillEffect.cpp \
           src/RenWangShield.cpp \
           src/ResolveEvent.cpp \
           src/SkillEffect.cpp \
           src/Slash.cpp \
           src/SouthernIntruder.cpp \
           src/Spear.cpp \
           src/StarterDeck.cpp \
           src/Static.cpp \
           src/TargetStruct.cpp \
           src/Thievery.cpp \
           src/TimeWalk.cpp \
           src/Transform.cpp \
           src/Trigger.cpp \
           src/TurnEvent.cpp \
           src/UseEvent.cpp \
           src/UseStruct.cpp \
           src/WeaponCard.cpp \
           src/WeaponGambit.cpp \
           src/YieldEvent.cpp \
           src/Zone.cpp
RESOURCES += \
    image.qrc
