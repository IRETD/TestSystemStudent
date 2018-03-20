#include "DataItemForModelTextDescription.h"

DataItemForModelTextDescription::DataItemForModelTextDescription()
{
}

QString DataItemForModelTextDescription::getText() {

    return m_Text;
}


void DataItemForModelTextDescription::setText( QString text ) {

    m_Text = text;
}
