// This file is autogenerated - see gen_fieldops.py
#include <bout/mesh.hxx>
#include <bout/region.hxx>
#include <field2d.hxx>
#include <field3d.hxx>
#include <globals.hxx>
#include <interpolation.hxx>

// Provide the C++ wrapper for multiplication of Field3D and Field3D
Field3D operator*(const Field3D& lhs, const Field3D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) {
    result[index] = lhs[index] * rhs[index];
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by multiplication with Field3D
Field3D& Field3D::operator*=(const Field3D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] *= rhs[index]; }

    checkData(*this);

  } else {
    (*this) = (*this) * rhs;
  }
  return *this;
}

// Provide the C++ wrapper for division of Field3D and Field3D
Field3D operator/(const Field3D& lhs, const Field3D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) {
    result[index] = lhs[index] / rhs[index];
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by division with Field3D
Field3D& Field3D::operator/=(const Field3D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] /= rhs[index]; }

    checkData(*this);

  } else {
    (*this) = (*this) / rhs;
  }
  return *this;
}

// Provide the C++ wrapper for addition of Field3D and Field3D
Field3D operator+(const Field3D& lhs, const Field3D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) {
    result[index] = lhs[index] + rhs[index];
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by addition with Field3D
Field3D& Field3D::operator+=(const Field3D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] += rhs[index]; }

    checkData(*this);

  } else {
    (*this) = (*this) + rhs;
  }
  return *this;
}

// Provide the C++ wrapper for subtraction of Field3D and Field3D
Field3D operator-(const Field3D& lhs, const Field3D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) {
    result[index] = lhs[index] - rhs[index];
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by subtraction with Field3D
Field3D& Field3D::operator-=(const Field3D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] -= rhs[index]; }

    checkData(*this);

  } else {
    (*this) = (*this) - rhs;
  }
  return *this;
}

// Provide the C++ wrapper for multiplication of Field3D and Field2D
Field3D operator*(const Field3D& lhs, const Field2D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  Mesh* localmesh = lhs.getMesh();

  BOUT_FOR(index, rhs.getRegion("RGN_ALL")) {
    const auto base_ind = localmesh->ind2Dto3D(index);
    for (int jz = 0; jz < localmesh->LocalNz; ++jz) {
      result[base_ind + jz] = lhs[base_ind + jz] * rhs[index];
    }
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by multiplication with Field2D
Field3D& Field3D::operator*=(const Field2D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, rhs.getRegion("RGN_ALL")) {
      const auto base_ind = fieldmesh->ind2Dto3D(index);
      for (int jz = 0; jz < fieldmesh->LocalNz; ++jz) {
        (*this)[base_ind + jz] *= rhs[index];
      }
    }

    checkData(*this);

  } else {
    (*this) = (*this) * rhs;
  }
  return *this;
}

// Provide the C++ wrapper for division of Field3D and Field2D
Field3D operator/(const Field3D& lhs, const Field2D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  Mesh* localmesh = lhs.getMesh();

  BOUT_FOR(index, rhs.getRegion("RGN_ALL")) {
    const auto base_ind = localmesh->ind2Dto3D(index);
    const auto tmp = 1.0 / rhs[index];
    for (int jz = 0; jz < localmesh->LocalNz; ++jz) {
      result[base_ind + jz] = lhs[base_ind + jz] * tmp;
    }
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by division with Field2D
Field3D& Field3D::operator/=(const Field2D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, rhs.getRegion("RGN_ALL")) {
      const auto base_ind = fieldmesh->ind2Dto3D(index);
      const auto tmp = 1.0 / rhs[index];
      for (int jz = 0; jz < fieldmesh->LocalNz; ++jz) {
        (*this)[base_ind + jz] *= tmp;
      }
    }

    checkData(*this);

  } else {
    (*this) = (*this) / rhs;
  }
  return *this;
}

// Provide the C++ wrapper for addition of Field3D and Field2D
Field3D operator+(const Field3D& lhs, const Field2D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  Mesh* localmesh = lhs.getMesh();

  BOUT_FOR(index, rhs.getRegion("RGN_ALL")) {
    const auto base_ind = localmesh->ind2Dto3D(index);
    for (int jz = 0; jz < localmesh->LocalNz; ++jz) {
      result[base_ind + jz] = lhs[base_ind + jz] + rhs[index];
    }
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by addition with Field2D
Field3D& Field3D::operator+=(const Field2D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, rhs.getRegion("RGN_ALL")) {
      const auto base_ind = fieldmesh->ind2Dto3D(index);
      for (int jz = 0; jz < fieldmesh->LocalNz; ++jz) {
        (*this)[base_ind + jz] += rhs[index];
      }
    }

    checkData(*this);

  } else {
    (*this) = (*this) + rhs;
  }
  return *this;
}

// Provide the C++ wrapper for subtraction of Field3D and Field2D
Field3D operator-(const Field3D& lhs, const Field2D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  Mesh* localmesh = lhs.getMesh();

  BOUT_FOR(index, rhs.getRegion("RGN_ALL")) {
    const auto base_ind = localmesh->ind2Dto3D(index);
    for (int jz = 0; jz < localmesh->LocalNz; ++jz) {
      result[base_ind + jz] = lhs[base_ind + jz] - rhs[index];
    }
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by subtraction with Field2D
Field3D& Field3D::operator-=(const Field2D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, rhs.getRegion("RGN_ALL")) {
      const auto base_ind = fieldmesh->ind2Dto3D(index);
      for (int jz = 0; jz < fieldmesh->LocalNz; ++jz) {
        (*this)[base_ind + jz] -= rhs[index];
      }
    }

    checkData(*this);

  } else {
    (*this) = (*this) - rhs;
  }
  return *this;
}

// Provide the C++ wrapper for multiplication of Field3D and BoutReal
Field3D operator*(const Field3D& lhs, const BoutReal rhs) {

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs[index] * rhs; }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by multiplication with BoutReal
Field3D& Field3D::operator*=(const BoutReal rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] *= rhs; }

    checkData(*this);

  } else {
    (*this) = (*this) * rhs;
  }
  return *this;
}

// Provide the C++ wrapper for division of Field3D and BoutReal
Field3D operator/(const Field3D& lhs, const BoutReal rhs) {

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs[index] / rhs; }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by division with BoutReal
Field3D& Field3D::operator/=(const BoutReal rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] /= rhs; }

    checkData(*this);

  } else {
    (*this) = (*this) / rhs;
  }
  return *this;
}

// Provide the C++ wrapper for addition of Field3D and BoutReal
Field3D operator+(const Field3D& lhs, const BoutReal rhs) {

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs[index] + rhs; }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by addition with BoutReal
Field3D& Field3D::operator+=(const BoutReal rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] += rhs; }

    checkData(*this);

  } else {
    (*this) = (*this) + rhs;
  }
  return *this;
}

// Provide the C++ wrapper for subtraction of Field3D and BoutReal
Field3D operator-(const Field3D& lhs, const BoutReal rhs) {

  Field3D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs[index] - rhs; }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field3D by subtraction with BoutReal
Field3D& Field3D::operator-=(const BoutReal rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] -= rhs; }

    checkData(*this);

  } else {
    (*this) = (*this) - rhs;
  }
  return *this;
}

// Provide the C++ wrapper for multiplication of Field2D and Field3D
Field3D operator*(const Field2D& lhs, const Field3D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  Mesh* localmesh = lhs.getMesh();

  BOUT_FOR(index, lhs.getRegion("RGN_ALL")) {
    const auto base_ind = localmesh->ind2Dto3D(index);
    for (int jz = 0; jz < localmesh->LocalNz; ++jz) {
      result[base_ind + jz] = lhs[index] * rhs[base_ind + jz];
    }
  }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for division of Field2D and Field3D
Field3D operator/(const Field2D& lhs, const Field3D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  Mesh* localmesh = lhs.getMesh();

  BOUT_FOR(index, lhs.getRegion("RGN_ALL")) {
    const auto base_ind = localmesh->ind2Dto3D(index);
    for (int jz = 0; jz < localmesh->LocalNz; ++jz) {
      result[base_ind + jz] = lhs[index] / rhs[base_ind + jz];
    }
  }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for addition of Field2D and Field3D
Field3D operator+(const Field2D& lhs, const Field3D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  Mesh* localmesh = lhs.getMesh();

  BOUT_FOR(index, lhs.getRegion("RGN_ALL")) {
    const auto base_ind = localmesh->ind2Dto3D(index);
    for (int jz = 0; jz < localmesh->LocalNz; ++jz) {
      result[base_ind + jz] = lhs[index] + rhs[base_ind + jz];
    }
  }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for subtraction of Field2D and Field3D
Field3D operator-(const Field2D& lhs, const Field3D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field3D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  Mesh* localmesh = lhs.getMesh();

  BOUT_FOR(index, lhs.getRegion("RGN_ALL")) {
    const auto base_ind = localmesh->ind2Dto3D(index);
    for (int jz = 0; jz < localmesh->LocalNz; ++jz) {
      result[base_ind + jz] = lhs[index] - rhs[base_ind + jz];
    }
  }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for multiplication of Field2D and Field2D
Field2D operator*(const Field2D& lhs, const Field2D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field2D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) {
    result[index] = lhs[index] * rhs[index];
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field2D by multiplication with Field2D
Field2D& Field2D::operator*=(const Field2D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] *= rhs[index]; }

    checkData(*this);

  } else {
    (*this) = (*this) * rhs;
  }
  return *this;
}

// Provide the C++ wrapper for division of Field2D and Field2D
Field2D operator/(const Field2D& lhs, const Field2D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field2D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) {
    result[index] = lhs[index] / rhs[index];
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field2D by division with Field2D
Field2D& Field2D::operator/=(const Field2D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] /= rhs[index]; }

    checkData(*this);

  } else {
    (*this) = (*this) / rhs;
  }
  return *this;
}

// Provide the C++ wrapper for addition of Field2D and Field2D
Field2D operator+(const Field2D& lhs, const Field2D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field2D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) {
    result[index] = lhs[index] + rhs[index];
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field2D by addition with Field2D
Field2D& Field2D::operator+=(const Field2D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] += rhs[index]; }

    checkData(*this);

  } else {
    (*this) = (*this) + rhs;
  }
  return *this;
}

// Provide the C++ wrapper for subtraction of Field2D and Field2D
Field2D operator-(const Field2D& lhs, const Field2D& rhs) {
  ASSERT1(areFieldsCompatible(lhs, rhs));

  Field2D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) {
    result[index] = lhs[index] - rhs[index];
  }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field2D by subtraction with Field2D
Field2D& Field2D::operator-=(const Field2D& rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {
    ASSERT1(areFieldsCompatible(*this, rhs));

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] -= rhs[index]; }

    checkData(*this);

  } else {
    (*this) = (*this) - rhs;
  }
  return *this;
}

// Provide the C++ wrapper for multiplication of Field2D and BoutReal
Field2D operator*(const Field2D& lhs, const BoutReal rhs) {

  Field2D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs[index] * rhs; }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field2D by multiplication with BoutReal
Field2D& Field2D::operator*=(const BoutReal rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] *= rhs; }

    checkData(*this);

  } else {
    (*this) = (*this) * rhs;
  }
  return *this;
}

// Provide the C++ wrapper for division of Field2D and BoutReal
Field2D operator/(const Field2D& lhs, const BoutReal rhs) {

  Field2D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs[index] / rhs; }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field2D by division with BoutReal
Field2D& Field2D::operator/=(const BoutReal rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] /= rhs; }

    checkData(*this);

  } else {
    (*this) = (*this) / rhs;
  }
  return *this;
}

// Provide the C++ wrapper for addition of Field2D and BoutReal
Field2D operator+(const Field2D& lhs, const BoutReal rhs) {

  Field2D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs[index] + rhs; }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field2D by addition with BoutReal
Field2D& Field2D::operator+=(const BoutReal rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] += rhs; }

    checkData(*this);

  } else {
    (*this) = (*this) + rhs;
  }
  return *this;
}

// Provide the C++ wrapper for subtraction of Field2D and BoutReal
Field2D operator-(const Field2D& lhs, const BoutReal rhs) {

  Field2D result{emptyFrom(lhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs[index] - rhs; }

  checkData(result);
  return result;
}

// Provide the C++ operator to update Field2D by subtraction with BoutReal
Field2D& Field2D::operator-=(const BoutReal rhs) {
  // only if data is unique we update the field
  // otherwise just call the non-inplace version
  if (data.unique()) {

    checkData(*this);
    checkData(rhs);

    BOUT_FOR(index, this->getRegion("RGN_ALL")) { (*this)[index] -= rhs; }

    checkData(*this);

  } else {
    (*this) = (*this) - rhs;
  }
  return *this;
}

// Provide the C++ wrapper for multiplication of BoutReal and Field3D
Field3D operator*(const BoutReal lhs, const Field3D& rhs) {

  Field3D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs * rhs[index]; }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for division of BoutReal and Field3D
Field3D operator/(const BoutReal lhs, const Field3D& rhs) {

  Field3D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs / rhs[index]; }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for addition of BoutReal and Field3D
Field3D operator+(const BoutReal lhs, const Field3D& rhs) {

  Field3D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs + rhs[index]; }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for subtraction of BoutReal and Field3D
Field3D operator-(const BoutReal lhs, const Field3D& rhs) {

  Field3D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs - rhs[index]; }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for multiplication of BoutReal and Field2D
Field2D operator*(const BoutReal lhs, const Field2D& rhs) {

  Field2D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs * rhs[index]; }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for division of BoutReal and Field2D
Field2D operator/(const BoutReal lhs, const Field2D& rhs) {

  Field2D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs / rhs[index]; }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for addition of BoutReal and Field2D
Field2D operator+(const BoutReal lhs, const Field2D& rhs) {

  Field2D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs + rhs[index]; }

  checkData(result);
  return result;
}

// Provide the C++ wrapper for subtraction of BoutReal and Field2D
Field2D operator-(const BoutReal lhs, const Field2D& rhs) {

  Field2D result{emptyFrom(rhs)};
  checkData(lhs);
  checkData(rhs);

  BOUT_FOR(index, result.getRegion("RGN_ALL")) { result[index] = lhs - rhs[index]; }

  checkData(result);
  return result;
}
